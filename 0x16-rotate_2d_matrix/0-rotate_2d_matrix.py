#!/usr/bin/python3
"""Module that rotates a 2d array (Matrix) clockwise."""


def rotate_2d_matrix(m):
    """Function that rotates the 2d array matrix clockwise."""
    t = [[m[-(1 + c)][r] for c in range(len(m))] for r in range(len(m[0]))]
    [(m.pop(0), m.append(r)) for r in t]


if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)
