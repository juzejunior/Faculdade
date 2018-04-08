#!/usr/bin/env python
# -*- coding: utf-8 -*

# Position of frame depends frame initial = mod m / 3, gave the position relative initial sequence point
#

CODON_SIZE = 3
start_codons = ['atg']
amino_acids = ["M"("abc", "cba", "cblow")]

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

# TODO Change each nucleotide to their reverse, receives a string and return a string

def get_receipes(sequence):
    string_test = "ggagccatgccctttttgtaaatc"
    sequence_list = list(string_test)
    codon = ""
    for nucleotide in sequence_list:
        if len(codon) == CODON_SIZE:
            if codon in start_codons:
                print(codon)
            codon = ""
            codon += nucleotide
        else:
            codon += nucleotide
    return codon

# TODO print each amino acids here, receives a list of list and print each rna and your respective amino acids

if __name__ == '__main__':
    print(amino_acids)
    #sequence = get_sequence(3462111, 3463457).lower()
    #codon_one = get_receipes(invert_sequence(sequence))
    # transform each from rna to nucleotide
