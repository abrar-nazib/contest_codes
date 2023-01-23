#!/usr/bin/env python
from requests_html import HTMLSession
import argparse
import markdownify
import os
import datetime


def determine_elem_names(platform, url=None):
    if (platform == 'hackerearth'):
        rt = {
            'title': 'div.title-panel div.title',
            'problem': 'div.problem-details'
        }
    elif (platform == 'leetcode'):
        rt = {
            'title': 'div.css-v3d350',
            'problem': 'div.content__u3I1 question-content__JfgR'
        }
    elif (platform == 'hackerrank'):
        rt = {
            'title': 'h1',
            'problem': 'div.hackdown-content'
        }
        create_basic_files(platform, url)
        exit()
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
        print("Platform not recognized")
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
    except:
        problem_title = 'Not Found'
        print("Title not found")
    problem_obj = html_object.find(problem_elem)
    try:
        problem_html = problem_obj[0].html
    except Exception as e:
        print(problem_obj)
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
    cppcontent = f"\n\
// Problem: {problem_title}\n\
// Link: {url}\n\
// Date: {tday}\n\
// Author: {author}\n\n\
#include <bits/stdc++.h>\n\
using namespace std;\n\n\
#define _DEBUG 1\n\n\
int main()\n\
{{\n\
#ifdef _DEBUG\n\
    freopen(\"input.txt\", \"r\", stdin);\n\
    freopen(\"output.txt\", \"w\", stdout);\n\
#endif\n\n\n\
    return 0;\n\
}}"
    os.mkdir('cpp')
    with open('cpp/soln.cpp', 'w') as cppfile:
        cppfile.write(cppcontent)
    with open("cpp/input.txt", "w") as inp:
        pass
    with open("cpp/output.txt", "w") as outp:
        pass


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
