#!/usr/bin/python3
""" This script defines a method canUnlockAll """


def canUnlockAll(boxes):
    """ This method determines if all the boxes can be opened. """
    no_repeated = []
    keys = [key for key in boxes[0] if key < len(boxes)]
    [no_repeated.append(key) for key in keys if key not in no_repeated]
    for i in no_repeated:
        if i > len(boxes) - 1:
            continue
        for n in boxes[i]:
            if n not in no_repeated and n != 0 and n < len(boxes):
                no_repeated.append(n)
    if len(no_repeated) == len(boxes) - 1:
        return True
    return False
