#!/usr/bin/env python3
"""Module for solving the N queens problem"""

import sys


def solve(N):
    """Works out and prints all possible solutions to the N queens problem"""
    board = create_board(N)
    add_queens(board)


def create_board(size):
    """creates a 2d array representing a square
    empty chess board filled with [ ]'s"""
    board = []
    row = []
    if isinstance(size, int):
        row = ["[ ]" for x in range(size)]
        board = [row.copy() for x in range(size)]
        return board


def add_queens(board, row_num=0):
    """Add's a queen to a row the board, checks to see if it is attacking
    any other queens, and either back tracks or recurse on the next row"""
    next = row_num + 1
    row = board[row_num]
    for column in range(len(row)):
        row[column] = " Q "
        if peaceful(board):
            if next < len(board):
                add_queens(board, next)
            elif next == len(board):
                # draw_board(board)
                print_queens(board)
        row[column] = "[ ]"


def peaceful(board):
    """returns true if no queens on the board are attacking each other"""
    queens = []
    for row in range(len(board)):
        for column in range(len(board[row])):
            if board[row][column] == " Q ":
                queens.append([row, column])

    for queen in queens:
        for each in queens:
            x1, y1 = queen[0], queen[1]
            x2, y2 = each[0], each[1]
            if x1 == x2 and y1 == y2:  # Checked against itself
                continue
            elif x1 == x2 or y1 == y2:  # Same row or column
                return False
            elif (abs((x1 - x2) / (y1 - y2)) == 1):  # Diagonal from another
                return False
    return True


def draw_board(board):
    """Draws the chess board stored in a 2d array"""
    for row in board:
        print(*row, sep=" ")
    print("")


def print_queens(board):
    """Prints the row and column of each queen on a board for a possible
    soultion."""
    queens = []
    for row in range(len(board)):
        for column in range(len(board[row])):
            if board[row][column] == " Q ":
                queens.append([row, column])
    print(queens)


def main():
    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        return
    N = sys.argv[1]
    if not N.isdigit():
        print("N must be a number")
        return
    N = int(N)
    if N < 4:
        print("N must be at least 4")
        return
    solve(N)


if __name__ == "__main__":
    main()
