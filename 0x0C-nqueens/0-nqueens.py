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


if __name__ == "__main__":
    sols = 0
    try:
        args = len(sys.argv)

    # no arg passed for size
    except Exception:
        print("Usage: nqueens N")
        exit(1)

    try:
        size = int(sys.argv[1])

    except IndexError:
        '''When arg not a number'''
        print("Usage: nqueens N")
        exit(1)
    except ValueError:
        print("N must be a number")
        exit(1)

    if(args == 0 | args > 2):
        print("Usage: nqueens N")
        exit(1)
    if(size < 4):
        print("N must be at least 4")
        exit(1)
    cells = list(nqueens(size))
    for solution in cells:
        print([list(sols) for sols in solution])
