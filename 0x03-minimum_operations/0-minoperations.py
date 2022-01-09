#!/usr/bin/python3
""" This script defines a method minOperations """


def minOperations(n):
    """ This method calculates the fewest number of operations needed
        to result in exactly n H characters in the file. """
    if primeNumber(n):
        return n
    else:
        return 2 + minOperations(maxMultiple(n))


def maxMultiple(n):
    """ This method return the highest multiple of a number n. """
    primes = [2, 3, 5, 7]
    for x in primes:
        if n % x == 0:
            return n / x
    return 0


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
