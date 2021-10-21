#!/usr/bin/python3
"""Module containing a function that checks if a list of ints is a valid
utf8 character"""


def validUTF8(data):
    """[summary]

    Args:
        data ([type]): [description]
    """
    n_bytes = 0
    for each in data:
        bi_str = format(each, '#010b')[-8:]
        if n_bytes == 0:
            for bit in bi_str:
                if bit == '0':
                    break
                n_bytes += 1

            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (bi_str[0] == '1' and bi_str[1] == '0'):
                return False
        n_bytes -= 1
    return (n_bytes == 0)

if __name__ == "__main__":
    data = [65]
    print(validUTF8(data))  # True

    data = [80, 121, 116, 104, 111, 110, 32, 105, 115,
    32, 99, 111, 111, 108, 33]
    print(validUTF8(data))  # True

    data = [229, 65, 127, 256]
    print(validUTF8(data)) # False

    data = [235, 140]
    print(validUTF8(data))  # False