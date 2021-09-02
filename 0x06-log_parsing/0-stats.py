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

    pattern = ("\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\s-\s\[\d+-\d+-\d+\s\d+:" +
               "\d+:\d+\.\d+\]\s\"GET\s/projects/260\sHTTP/1.1\"\s\d\d\d\s\d+")
    return bool(re.match(pattern=pattern, string=string))


def print_codes(size, code_dict):
    """Prints information formated per task requirments.

    Args:
        size (int): Total filesize
        code_dict (dict): Dictionary of status code totals.
    """
    print("File size: {}".format(size))
    for key, value in sorted(code_dict.items()):
        if value > 0:
            print("{}: {}".format(key, value))


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
                print_codes(total_size, status_codes)
            else:
                count += 1
        print_codes(total_size, status_codes)

    except KeyboardInterrupt:
        print_codes(total_size, status_codes)


if __name__ is not "__main__":
    main()
