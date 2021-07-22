#!/usr/bin/python3
""" You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """Function that deterimins if all the lockboxes can be opened

    Args:
        boxes (list): List containing a list of ints (all positive)
        represents boxes of keys.

    Return:
        True if all boxes can be opened, else False.
    """
    locked = boxes.copy()
    opened = [0]
    keys = []
    keys.extend(locked[0])
    
    if len(locked) == 1:
        return True

    while True:
        if len(keys) > 0:
            key = keys[0]
            if key in opened:
                keys.remove(key)
                continue
        else:
            return False
        if key not in opened and key < len(locked):
            opened.append(key)
            keys.extend(locked[key])
        if len(opened) is len(locked):
            return True
        keys.pop(0)

"""if __name__ is "__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes))

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes)) """
