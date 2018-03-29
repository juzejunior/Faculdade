#!/usr/bin/env python
# -*- coding: utf-8 -*

''' Objective: Receive a interval and get string between it from a file
    Params: initial_position(initial carater position), final_position(final caracter position)
'''
def get_sequence(initial_position, final_position):
    f = open('sequence.txt', 'r')
    next(f)
    sequence = ""
    for position in range(initial_position, final_position):
        sequence += str(f.read(position))
    return sequence

def invert_sequence(sequence):
    return sequence

def print_proteins(sequence):
    print(sequence)

if __name__ == '__main__':
    sequence = get_sequence(3462111, 3463457)
    print_proteins(invert_sequence(sequence))
