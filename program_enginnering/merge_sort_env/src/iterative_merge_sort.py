#!/usr/bin/env python
# -*- coding: utf-8 -*
import sys
import time

def merge_sort(xs):
    """Inplace merge sort of array without recursive. The basic idea
    is to avoid the recursive call while using iterative solution. 
    The algorithm first merge chunk of length of 2, then merge chunks
    of length 4, then 8, 16, .... , until 2^k where 2^k is large than 
    the length of the array
    """
    unit = 1
    while unit <= len(xs):
        h = 0
        for h in range(0, len(xs), unit * 2):
            l, r = h, min(len(xs), h + 2 * unit)
            mid = h + unit
            # merge xs[h:h + 2 * unit]
            p, q = l, mid
            while p < mid and q < r:
                if xs[p] < xs[q]: p += 1
                else:
                    tmp = xs[q]
                    xs[p + 1: q + 1] = xs[p:q]
                    xs[p] = tmp
                    p, mid, q = p + 1, mid + 1, q + 1
        unit *= 2    
    return xs

def get_tuple_from_file(file_name):
    tuple_list = []

    with open(file_name, 'r') as fp:
        for line in fp:
            current_line = line.split(';')
            value = int(current_line[1])
            tuple_list.append(value)
   
    return tuple_list

def show_pair_list(list):
    for item in list:
        print(str(item))

file_name = sys.argv[1]
list_pair = get_tuple_from_file(file_name)

start = time.time()
ord_list = merge_sort(list_pair)
end = time.time()

show_pair_list(ord_list)
print("\nTempo para ordenação: "+str(round(end - start, 3))+" segundos.")