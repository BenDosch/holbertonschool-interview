#!/usr/bin/python3
""" Module to solve the N Queens Problem """

import sys


def nowWhat(board, size):
    """
    Method to assess current state of board and determine which positions
    are still available. If board is empty every postion available.
    Args:
        board:
            frozen set(x, y) tuples with position of existing queens
        size:
            rows and columns
    Returns:
        Positions(x, y) remaining that do not conflict with current queens
    """
    rowsTaken = frozenset(x for x, y in board)
    rowsFree = (x for x in range(size) if x not in rowsTaken)
    colsTaken = frozenset(y for x, y in board)
    colsFree = (y for y in range(size) if y not in colsTaken)
    bothFree = ((x, y) for x in rowsFree for y in colsFree)
    diagA = frozenset(x + y for x, y in board)
    diagB = frozenset(x - y for x, y in board)
    return ((x, y) for x, y in bothFree if x + y not in diagA
            and x - y not in diagB)


def sorted_remaining(board, size):
    """ Wrapper function for nowWhat """
    if board:
        maxX = max(x for x, y in board)
    else:
        maxX = -1
    return ((x, y) for x, y in nowWhat(board, size) if x > maxX)


def nqueens(size, board=[]):
    """
    Method to generate all solutions of nQueens problem
    Args:
        size:
            argv 1 postion, must be int greater than 4
        board:
            frozen set(x, y) tuples with position of existing queens
    Returns:
        set of solutions(x, y) tuples with positions where queens
        can be placed without conflict
    """
    board = board or frozenset()
    if len(board) == size:
        yield board
    for position in sorted_remaining(board, size):
        newBoard = board.union((position,))
        yield from nqueens(size, newBoard)

def main():
    sols = 0
    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        return
    N = sys.argv[1]
    if N.isdigit() is not True:
        print("N must be a number")
        return
    N = int(N)
    if N < 4:
        print("N must be at least 4")
        return
    cells = list(nqueens(N))
    for solution in cells:
        print([list(sols) for sols in solution])

if __name__ == "__main__":
    main()
