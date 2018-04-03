#!/usr/bin/env python
# -*- coding: utf-8 -*


CODON_SIZE = 3
start_codons = ['atg', 'ctg']

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
    return ''.join(reversed(sequence))

def get_receipes(sequence):
    string_test = "ggagccatgccctttttgtaaatc"
    sequence_list = list(string_test)
    codon = ""
    for nucleotide in sequence_list:
        if len(codon) == CODON_SIZE:
            print(codon)
            codon = ""
            codon += nucleotide
        else:
            codon += nucleotide
        """if len(codon) != CODON_SIZE:
            codon += nucleotide
        else:
            print(codon)
            codon = """""
    return codon

if __name__ == '__main__':
    sequence = get_sequence(3462111, 3463457).lower()
    codon_one = get_receipes(invert_sequence(sequence))
    print(codon_one)
