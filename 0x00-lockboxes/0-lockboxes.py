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
    opened = []
    keys = [0]
    new_keys = []
    while True:
        for key in keys:
            new_keys.extend(locked[key])  # Remove keys from box & set asside
            locked[key] = []
            opened.append(key)  # Mark box opened

        if len(opened) == len(locked):  # Check if all boxes are open
            return True
        if new_keys == []:  # check to see if there are any more keys left
            return False
    # get ready to check keys that were set asside.
        keys = [x for x in (set(new_keys)) if x not in opened
                and x >= 0 and x < len(locked)]  
        new_keys = []


"""if __name__ == "__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))  # True

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes))  # True

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes))  # False

    boxes  = [list(range(1000)) for x in range(1000)]
    print(canUnlockAll(boxes))  # True"""
