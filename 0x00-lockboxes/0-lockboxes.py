#!/usr/bin/python3
""" This script defines a method canUnlockAll """


def canUnlockAll(boxes):
    """ This method determines if all the boxes can be opened. """
    keys = [key for key in boxes[0]]
    for i in keys:
        for n in boxes[i]:
            if n not in keys and n != 0:
                keys.append(n)
    if len(keys) == len(boxes) - 1:
        return True
    return False
