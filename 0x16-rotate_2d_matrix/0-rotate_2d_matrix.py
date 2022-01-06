#!/usr/bin/python3
"""Module that rotates a 2d array (Matrix) clockwise."""


def rotate_2d_matrix(matrix):
    """Function that rotates the 2d array matrix clockwise."""
    temp = [[matrix[-(1 + col)][row] for col in range(len(matrix))]
            for row in range(len(matrix[0]))]
    matrix.clear()
    [matrix.append(row) for row in temp]


if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)
