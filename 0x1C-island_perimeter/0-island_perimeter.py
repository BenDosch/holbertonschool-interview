#!/usr/bin/python3
""" Module containing a function
that finds the perimiter of and island"""


def island_perimeter(grid):
    """Calculates the perimeter of an island"""
    perimiter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i != 0 and grid[i - 1][j]:
                    pass
                else:
                    perimiter += 1
                if i != len(grid) - 1 and grid[i + 1][j]:
                    pass
                else:
                    perimiter += 1
                if j != 0 and grid[i][j - 1]:
                    pass
                else:
                    perimiter += 1
                if j != len(grid[i]) - 1 and grid[i][j + 1]:
                    pass
                else:
                    perimiter += 1
    return perimiter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
