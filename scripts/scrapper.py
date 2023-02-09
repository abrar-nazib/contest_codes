#!/usr/bin/env python
from requests_html import HTMLSession
import argparse
import markdownify
import os
import datetime
import re
from codeEditorOpener import *


def cleanTitle(problem_title: str):
    """ Cleans the problem title statement by replacing specific characters

    Args:
        problem_title: String containing unsanitized problem title

    Returns:
        problem_title: String containing sanitized problem title
    """
    problem_title = re.sub("[- ]", "_", problem_title)
    problem_title = re.sub("[().]", "", problem_title)
    return problem_title


def chooseHTMLelems(platform: str, url: str = None):
    """Chooses html elements to scrap according to cp platform

    Args:
        platform: Name of online platform. Case sensitive. Available platforms: hackerearth, leetcode, geeksforgeeks, codeforces

    Returns:
        rt: A dictionary containing 'title' and 'problem'

    """
    if (platform == 'hackerearth'):
        rt = {
            'title': 'div.title-panel div.title',
            'problem': 'div.problem-details'
        }
    elif (platform == 'leetcode'):
        rt = {
            'title': 'span.mr-2',
            'problem': 'div._1l1MA'
        }
    # elif (platform == 'hackerrank'):
    #     rt = {
    #         'title': 'h1',
    #         'problem': 'div.hackdown-content'
    #     }

    elif (platform == 'geeksforgeeks'):
        rt = {
            'title': 'h3.g-m-0',
            'problem': 'div.problems_problem_content__Xm_eO'
        }

    elif (platform == 'codeforces'):
        rt = {
            'title': 'div.header div.title',
            'problem': 'div.problem-statement'
        }
    else:
        print("Platform not recognized. Not creating README")
        create_basic_files(platform, url)
        if (os.name == "posix"):    # only open editor if in popos
            open_editor()
        exit()
    return rt


def parse_problem(platform, url):
    session = HTMLSession()
    elem_names = chooseHTMLelems(platform, url)
    title_elem = elem_names['title']
    problem_elem = elem_names['problem']

    print("[*] Sending Request...")

    res = session.get(url)

    html_object = res.html
    html_object.render(timeout=60)

    print("[+] Response Recieved.")

    try:
        problem_title = html_object.find(title_elem)[0].text
        print(f"[+] Problem Title Found. Title: {problem_title}")
        time.sleep(0.2)
    except Exception as e:
        problem_title = 'Not Found'
        print("[-] Problem Title not found")
        print(e)
    problem_obj = html_object.find(problem_elem)
    try:
        problem_html = problem_obj[0].html
        print("[+] Problem statement found")
        time.sleep(0.2)
    except Exception as e:
        print("[-] Problem Statement not found")
        print(e)
        exit()

    problem_text = markdownify.markdownify(problem_html, heading_style="ATX")
    problem_text = f"# {problem_title} \n \n link: {url} \n \n {problem_text}"
    readme_title = cleanTitle(problem_title)
    with open(f"{readme_title}.md", 'w') as f:
        f.write(problem_text)
        print("[+] README.md File Created.")

    # --------------------------------
    # Parsing Inputs and Outputs
    # --------------------------------
    input_elem = ""
    output_elem = ""
    try:
        input_elem = html_object.find("div.input pre")[0].text
    except:
        print("[-] Could not extract test input")

    try:
        output_elem = html_object.find("div.output pre")[0].text
    except:
        print("[-] Could not extract test output")
    return problem_title, input_elem, output_elem


def createCPPTemplate(problem_title, url):
    """Creates cpp template files necessary for solving the problem"""
    tday = datetime.date.today()
    tday = tday.strftime("%d-%m-%Y")
    author = "Nazib Abrar"
    detailPattern = re.compile(r'\$detail\$')
    detailContent = ""
    detailContent += f"Problem: {problem_title}\n"
    detailContent += f"Link: {url}\n"
    detailContent += f"Date: {tday}\n"
    detailContent += f"Author: {author}\n"

    with open('/home/abrar/contest_codes/scripts/cpp_template.cpp', 'r') as f:
        cppContent = ""
        for line in f.readlines():
            if (detailPattern.findall(line) == []):
                cppContent += line
            else:
                cppContent += detailContent

    problem_title = cleanTitle(problem_title)

    cppFileName = f"soln_{problem_title}.cpp"
    with open(cppFileName, 'w') as cppfile:
        cppfile.write(cppContent)
    print(f"[+] Created Template File {cppFileName}")
    time.sleep(0.2)
    return cppFileName


def create_basic_files(problem_title, url, input="", output=""):

    templateFileName = createCPPTemplate(problem_title, url)

    with open("input.txt", "w") as inp:
        inp.write(input)
    with open("output.txt", "w") as outp:
        pass
    return templateFileName


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="A web scrapper for competitive programming problems")
    parser.add_argument("Platform",
                        metavar="platform",
                        type=str,
                        help="Name of the platform. ex: hackerearth, leetcode, hackerrank, geeksforgeeks, codeforces",
                        )
    parser.add_argument("Url",
                        metavar="url",
                        type=str,
                        help="Problem url"
                        )

    args = parser.parse_args()

    url = args.Url
    platform = args.Platform
    title, input, output = parse_problem(platform=platform, url=url)
    filename = create_basic_files(title, url, input, output)
    print(filename)
    if (os.name == "posix"):    # only open editor if in posix
        open_editor(filename)
