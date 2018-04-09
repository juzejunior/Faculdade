#!/usr/bin/env python
# -*- coding: utf-8 -*

# Position of frame depends frame initial = mod m / 3, gave the position relative initial sequence point
#

CODON_SIZE = 3
start_codons = 'atg'
end_codons = 'ccc'
amino_acids = ["M", ("abc", "cba", "cblow")]

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

def get_rna(sequence):
    result = ""
    for nucleotideo in sequence:
        if (nucleotideo == 'a'):
            result += "u"
        elif (nucleotideo == "t"):
            result += "a"
        elif (nucleotideo == "g"):
            result += "c"
        elif (nucleotideo == "c"):
            result += "g"
    return result

def get_reverse_nucleotide(sequence):
    reversed = invert_sequence(sequence)
    result = ""
    for nucleotideo in reversed:
        if (nucleotideo == 'a'):
            result += "t"
        elif (nucleotideo == "t"):
            result += "a"
        elif (nucleotideo == "g"):
            result += "c"
        elif (nucleotideo == "c"):
            result += "g"
    return result

def get_receipes(sequence):
    #string_test = "ggagccatgccctttttgtaaatgc"
    #sequence_list = list(string_test)
    codon = ""
    previous = ""
    position = 0
    pos_ini = 0
    pos_fim = 0
    start = 0
    end = 0
    for nucleotide in sequence:
        position+=1
        if (start == 0):
            if (nucleotide == start_codons[pos_ini]):
                codon += nucleotide
                pos_ini+=1
                if (pos_ini==3):
                    start = 1
            else:
                codon = ""
                pos_ini = 0
        elif (start == 1):
            if (nucleotide == end_codons[pos_fim]):
                previous += nucleotide
                pos_fim += 1
                if (pos_fim == 3):
                    codon += end_codons
                    start = 2
            elif (previous != ""):
                pos_fim = 0
                if (nucleotide == end_codons[pos_fim]):
                    pos_fim += 1
                else:
                    codon += previous
                    codon += nucleotide
                    previous = ""
            else:
                codon += nucleotide
                pos_fim = 0
                if (nucleotide == end_codons[pos_fim]):
                    pos_fim += 1
                else:
                    previous = ""
        elif (start == 2): break

    return codon

# TODO print each amino acids here, receives a list of list and print each rna and your respective amino acids


if __name__ == '__main__':
    sequence = get_sequence(3462111, 3463457).lower()
    # codon_one = get_receipes(invert_sequence(sequence))
    print(get_receipes(sequence))
    # transform each from rna to nucleotide
