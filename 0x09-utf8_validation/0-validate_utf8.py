#!/usr/bin/python3
"""Module containig"""

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
                if bit == '0': break
                n_bytes += 1
                
            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (bi_str[0] == '1' and bi_str[1] == '0'):
                return False
        n_bytes -= 1
    return True