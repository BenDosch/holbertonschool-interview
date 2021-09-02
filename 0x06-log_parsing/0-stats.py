#!/usr/bin/python3
"""Module containig work for a Holberton interview prep question on log
parsing.
"""

import sys
import re


def format_check(string):
    """Function that checks if the format of a string matches
    <IP Address> - [<date>] "GET /pjts/260 HTTP/1.1" <status code> <file size>

    Args:
        string (str): String to check formating of.

    Returns:
        True if stiring matches the format, else False.
    """

    pattern = ("\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\s-\s\[\d+-\d+-\d+\s\d+:\d+" +
               ":\d+\.\d+\]\s\"GET\s/projects/260\sHTTP/1.1\"\s\d\d\d\s\d+")
    return bool(re.match(pattern=pattern,string=string))


def main():
    """Main function for problem.
    """
    status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
    count = 0
    total_size = 0
    try:
        for line in sys.stdin:
            if format_check(line):
                line_parts = line.split()
                total_size += int(line_parts[-1])
                if line_parts[-2] in status_codes.keys():
                    status_codes["{}".format(line_parts[-2])] += 1
            if count >= 9:
                count = 0
                print("File size: {}".format(total_size))
                print("200: {}\n401: {}\n403: {}\n404: {}\n405: {}\n500: {}"
                        .format(status_codes["200"], status_codes["401"],
                            status_codes["403"], status_codes["404"], 
                            status_codes["405"], status_codes["500"]
                        )
                    )
            else:
                count += 1
    finally:
        print("File size: {}".format(total_size))
        print("200: {}\n401: {}\n403: {}\n404: {}\n405: {}\n500: {}"
                .format(status_codes["200"], status_codes["401"],
                    status_codes["403"], status_codes["404"], 
                    status_codes["405"], status_codes["500"]
                )
            )
    print("File size: {}".format(total_size))
    print("200: {}\n401: {}\n403: {}\n404: {}\n405: {}\n500: {}"
        .format(status_codes["200"], status_codes["401"],
        status_codes["403"], status_codes["404"], 
        status_codes["405"], status_codes["500"]
    ))


if __name__  is not "__main__":
    main()
    # 153.228.230.189 - [2021-08-31 18:17:00.695576] "GET /projects/260 HTTP/1.1" 405 825
