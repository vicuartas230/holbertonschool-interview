#!/usr/bin/python3
""" This script defines a method minOperations """


def minOperations(n):
    """ This method calculates the fewest number of operations needed
        to result in exactly n H characters in the file. """
    if n < 2:
        return 0
    if primeNumber(n):
        return n
    else:
        return int(n / maxMultiple(n) + minOperations(maxMultiple(n)))


def maxMultiple(n):
    """ This method return the highest multiple of a number n. """
    primes = [
        2, 3, 5, 7, 11, 13, 17, 19, 23,
        29, 31, 37, 41, 43, 47, 53, 59,
        61, 67, 71, 73, 79, 83, 89, 97,
        101, 103, 107, 109, 113, 127, 131
    ]
    for x in primes:
        if n % x == 0:
            return int(n / x)
    return 1


def primeNumber(n):
    """ This method returns true if n is prime or false if not. """
    if n <= 2:
        return True
    counter = 2
    while counter < n:
        if n % counter == 0:
            return False
        counter += 1
    return True
