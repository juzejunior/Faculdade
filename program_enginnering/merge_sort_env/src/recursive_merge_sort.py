#!/usr/bin/env python
# -*- coding: utf-8 -*
import sys
import time

def merge(left, right):
    if not len(left) or not len(right):
        return left or right
 
    result = []
    i, j = 0, 0
    while (len(result) < len(left) + len(right)):
        if left[i][1] <= right[j][1]:
            result.append(left[i])
            i+= 1
        else:
            result.append(right[j])
            j+= 1
        if i == len(left) or j == len(right):
            result.extend(left[i:] or right[j:])
            break
 
    return result
 
def mergesort(list):
    if len(list) < 2:
        return list
 
    middle = int(len(list)/2)
    left = mergesort(list[:middle])
    right = mergesort(list[middle:])
 
    return merge(left, right)

def get_tuple_from_file(file_name):
    tuple_list = []
    keys = []
    values = []
    with open(file_name, 'r') as fp:
        for line in fp:
            current_line = line.split(';')
            indice = int(current_line[0])
            value = int(current_line[1])
            keys.append(indice)
            values.append(value)
    tuple_list = list(zip(keys, values))
    return tuple_list

def show_pair_list(list):
    for item in list:
        print(str(item[0])+" ; "+str(item[1]))

file_name = sys.argv[1]
list_pair = get_tuple_from_file(file_name)

start = time.time()
sorted_list = mergesort(list_pair)
end = time.time()

show_pair_list(mergesort(list_pair))
print("\nTempo para ordenação: "+str(round(end - start, 3))+" segundos.")