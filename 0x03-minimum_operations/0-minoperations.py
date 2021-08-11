#!/usr/bin/env python3
"""Module containing functions to solve the interview preperation question
"""

def minOperations(n):
    """Function that calculates the fewest number of operations needed to
    result in exactly n H characters in the file.

    Args:
        n (int): Desired number of H's in a file.

    Returns:
        min (int): minimum number of operations needed.
    """
    if n <= 1:
        return 0
    else:
        factors = prime_factors(n)
        if factors == []:
            return 0
        else:
            return sum(factors)

def prime_factors(n):
    """Calculates the prime factors of a number

    Args:
        n (int): Number to factor

    Returns:
        factors (list[(ints)]): List of prime factors greater than 1 for n.
            Returns empty if not possible.
    """
    if n < 2:
        return []
    factors = []
    i = 2
    while i <= n:
        if n % i == 0:
            factors.append(i)
            n /= i
        else:
            i += 1
    return factors

if __name__ == "__main__":
    a = prime_factors(2)
    b = prime_factors(9)
    c = prime_factors(30)
    d = prime_factors(1)
    print("A:{}  B:{}  C:{}  D:{}".format(a, b, c, d))
    a = minOperations(2)
    b = minOperations(9)
    c = minOperations(30)
    d = minOperations(1)
    print("A:{}  B:{}  C:{}  D:{}".format(a, b, c, d))
