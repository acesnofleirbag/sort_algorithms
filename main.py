#!/usr/bin/env python3

from typing import List

def selection_sort(arr: List):
    for x in range(len(arr) - 1):
        _min: int = x

        for y in range(x, len(arr)):
            if (arr[y] < arr[_min]): _min = y

        arr[x], arr[_min] = arr[_min], arr[x]

def bubble_sort(arr: List):
    for _ in range(len(arr)):
        for i in range(len(arr) - 1):
            if (arr[i] > arr[i + 1]):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]

def insertion_sort(arr: List):
    for i in range(1, len(arr)):
        cur, pre = arr[i], i - 1

        while (pre >= 0 and arr[pre] > cur):
            arr[pre + 1] = arr[pre]
            pre -= 1

        arr[pre + 1] = cur

def merge(arr: List, start: int, mid: int, end: int):
    left, right = arr[start:mid], arr[mid:end]
    tleft, tright = 0, 0

    for i in range(start, end):
        if (tleft >= len(left)):
            arr[i] = right[tright]
            tright += 1
        elif (tright >= len(right)):
            arr[i] = left[tleft]
            tleft += 1
        elif (left[tleft] < right[tright]):
            arr[i] = left[tleft]
            tleft += 1
        else:
            arr[i] = right[tright]
            tright += 1

def merge_sort(arr: List, start: int = 0, end: int = None):
    if (end == None): end = len(arr)

    if (end - start > 1):
        mid = (end + start) // 2
        merge_sort(arr, start, mid)
        merge_sort(arr, mid, end)
        merge(arr, start, mid, end)

def quick_sort(arr: List, start: int = 0, end: int = None):
    if (end == None): end = len(arr) - 1

    if (start < end):
        pivot = partition(arr, start, end)
        quick_sort(arr, start, pivot - 1)
        quick_sort(arr, pivot + 1, end)

def partition(arr: List, start: int, end: int):
    pivot: int = arr[end]
    _min: int = start

    for i in range(start, end):
        if (arr[i] <= pivot):
            arr[i], arr[_min] = arr[_min], arr[i]
            _min += 1

    arr[_min], arr[end] = arr[end], arr[_min]

    return _min

def main():
    one = [ 9, 6, 2, 3, 90, 39, 20 ]
    two = [ 3, 2, 1 ]
    three = [ 30, 40, 20, 10, 99 ]
    four = [ 5, 15, 10, 25, 20, 30, 35 ]
    five = [ 7, 6, 5, 4, 3, 2, 1 ]

    bubble_sort(one)
    print(f"bubble: {one}", end="\n")

    selection_sort(two)
    print(f"selection: {two}", end="\n")

    insertion_sort(three)
    print(f"insertion: {three}", end="\n")

    merge_sort(four)
    print(f"merge: {four}", end="\n")

    quick_sort(five)
    print(f"quick: {five}", end="\n")

if __name__ == "__main__":
    main()
