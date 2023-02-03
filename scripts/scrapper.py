#!/usr/bin/env python
from requests_html import HTMLSession
import argparse
import markdownify
import os
import datetime
import time
import signal


def determine_elem_names(platform, url=None):
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
    elem_names = determine_elem_names(platform, url)
    title_elem = elem_names['title']
    problem_elem = elem_names['problem']
    # url = 'https://www.hackerearth.com/problem/algorithm/mangoes/'
    res = session.get(url)
    html_object = res.html
    html_object.render(timeout=60)

    try:
        problem_title = html_object.find(title_elem)[0].text
        print(f"Problem Title: {problem_title}")
    except Exception as e:
        problem_title = 'Not Found'
        print("Title not found")
        print(e)
    problem_obj = html_object.find(problem_elem)
    try:
        problem_html = problem_obj[0].html
        print("Problem statement found")
    except Exception as e:
        print("Problem Statement not found")
        print(e)
        exit()

    problem_text = markdownify.markdownify(problem_html, heading_style="ATX")
    problem_text = f"# {problem_title} \n \n link: {url} \n \n {problem_text}"
    with open('README.md', 'w') as f:
        f.write(problem_text)
    return problem_title


def create_basic_files(problem_title, url):
    tday = datetime.date.today()
    tday = tday.strftime("%d-%m-%Y")
    author = 'Nazib Abrar'
    cppcontent = f"#define _LOCAL 1\n\n\
// Problem: {problem_title}\n\
// Link: {url}\n\
// Date: {tday}\n\
// Author: {author}\n\n\
#include <bits/stdc++.h>\n\
using namespace std;\n\n\
int main()\n\
{{\n\
#ifdef _LOCAL\n\
    freopen(\"input.txt\", \"r\", stdin);\n\
    freopen(\"output.txt\", \"w\", stdout);\n\
#endif\n\n\
    ios::sync_with_stdio(0);\n\
    cin.tie(0);\n\n\n\
    return 0;\n\
}}"
    if (os.path.isdir('cpp')):
        print("cpp folder already exists")
    else:
        os.mkdir('cpp')
    with open('cpp/soln.cpp', 'w') as cppfile:
        cppfile.write(cppcontent)
    with open("cpp/input.txt", "w") as inp:
        pass
    with open("cpp/output.txt", "w") as outp:
        pass


def open_editor():
    time.sleep(1)
    os.system("code cpp")
    time.sleep(1)
    os.system("code cpp/output.txt -n; code cpp/input.txt -n")
    os.kill(os.getppid(), signal.SIGHUP)    # destroy the terminal


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
    title = parse_problem(platform=platform, url=url)
    create_basic_files(title, url)
    if (os.name == "posix"):    # only open editor if in posix
        open_editor()
