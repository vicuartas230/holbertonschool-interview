#!/usr/bin/python3
""" This script defines a method canUnlockAll """


def canUnlockAll(boxes):
    """ This method determines if all the boxes can be opened. """
    keys = [key for key in boxes[0] if key < len(boxes)]
    keys = list(set(keys))
    for i in keys:
        if i > len(boxes) - 1:
            continue
        for n in boxes[i]:
            if n not in keys and n != 0 and n < len(boxes):
                keys.append(n)
    if len(keys) == len(boxes) - 1:
        return True
    return False
