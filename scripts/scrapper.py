#! /usr/bin/env python
from requests_html import HTMLSession
import argparse
import markdownify


def determine_elem_names(platform):
    if (platform == 'hackerearth'):
        rt = {
            'title': 'div.title-panel div.title',
            'problem': 'div.problem-details'
        }
    elif (platform == 'hackerrank'):
        rt = {
            'title': 'h1',
            'problem': 'div.hackdown-content'
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
    elem_names = determine_elem_names(platform=platform)
    title_elem = elem_names['title']
    problem_elem = elem_names['problem']
    # url = 'https://www.hackerearth.com/problem/algorithm/mangoes/'
    res = session.get(url)
    html_object = res.html
    html_object.render(timeout=60)

    try:
        problem_title = html_object.find(title_elem)[0].text
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


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="A web scrapper for competitive programming problems")
    parser.add_argument("Platform",
                        metavar="platform",
                        type=str,
                        help="Name of the platform"
                        )
    parser.add_argument("Url",
                        metavar="url",
                        type=str,
                        help="Problem url"
                        )

    args = parser.parse_args()

    url = args.Url
    platform = args.Platform
    parse_problem(platform=platform, url=url)
