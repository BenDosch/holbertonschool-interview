#!/usr/bin/env python3
"""Module contains the function rain that given a list of non-negative integers
representing the heights of walls with unit width 1, as if viewing the
cross-section of a relief map, calculate how many square units of water will
be retained after it rains."""


def rain(walls):
    """Function that that given a list of non-negative integers representing
    the heights of walls with unit width 1, as if viewing the cross-section
    of a relief map, calculate how many square units of water will be retained
    after it rains."""
    # Check input
    if (not isinstance(walls, list) or len(walls) < 2):
        return 0
    # Set  initial values.
    tallest, tallest_2 = walls[0], len(walls) - 1
    # Find 2 tallest walls.
    for i in range(len(walls)):
        if walls[i] >= walls[tallest]:
            tallest_2 = tallest
            tallest = i
        elif walls[i] > tallest_2:
            tallest_2 = i

    print("{}".format(walls))
    print("tallest: {}->{} tallest_2: {}->{}".format(
        tallest, walls[tallest], tallest_2, walls[tallest_2])
        )
    # Check that there were 2 walls to retain rain.
    if walls[tallest] == 0 or walls[tallest_2] == 0:
        return 0
    # Find the left and right position of walls & size of walls in water.
    left = min((tallest, tallest_2))
    right = max((tallest, tallest_2))
    filler = sum(walls[left + 1: right])
    print("filler: {}".format(filler))
    # Get dimensions of space between walls and calculate water inside.
    height = min((walls[tallest], walls[tallest_2]))
    width = right - left - 1
    water = (height * width) - filler
    print("height: {} width: {} water: {}".format(height, width, water))
    # Return water found and recurse on list of walls to left and right of 
    # the walls found.
    return water + rain(walls[:left + 1]) + rain(walls[right])


if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))

# Expected output
"""
6
6
"""
