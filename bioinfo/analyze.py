#!/usr/bin/env python
# -*- coding: utf-8 -*
import sys
CODON_SIZE = 3
initial_position = 3462111
final_position = 3463457
middle_position = initial_position

start_codons = ['atg', 'gtg']
end_codons = ['agg', 'taa', 'tga']
amino_acids = {'I': {0: 'att', 1:'atc', 2: 'ata'},
              'L': {0: 'ctt', 1:'ctc', 2:'cta', 3: 'ctg', 4: 'tta', 5: 'ttg'},
              'V': {0: 'gtt', 1: 'tgc', 2: 'gta', 3: 'gtg'},
              'F': {0: 'ttt', 1: 'ttc'},
              'M': {0: 'atg'},
              'C': {0: 'tgt', 1: 'tgc'},
              'A': {0: 'gct', 1: 'gcc', 2: 'gca', 3: 'gcg'},
              'G': {0: 'ggt', 1: 'ggc', 2: 'gga', 3: 'ggg'},
              'P': {0: 'cct', 1: 'ccc', 2: 'cca', 3: 'ccg'},
              'T': {0: 'act', 1: 'acc', 2: 'aca', 3: 'acg'},
              'S': {0: 'tct', 1: 'tcc', 2: 'tca', 3: 'tcg', 4: 'agt', 5: 'agc'},
              'Y': {0: 'tat', 1: 'tac'},
              'W': {0: 'tgg'},
              'Q': {0: 'caa', 1: 'cag'},
              'N': {0: 'aat', 1: 'aac'},
              'H': {0: 'cat', 1: 'cac'},
              'E': {0: 'gaa', 1: 'gag'},
              'D': {0: 'gat', 1: 'gac'},
              'K': {0: 'aaa', 1: 'aag'},
              'R': {0: 'cgt', 1: 'cgc', 2: 'cga', 3: 'cgg', 4: 'aga', 5: 'agg'},
              'Stop': {0: 'taa', 1: 'tag', 2: 'tga'}
              }

''' Objective: Receive a interval and get string between it from a file
    Params: initial_position(initial carater position), final_position(final caracter position)
     for i in range(initial_position, final_position+1):
         new_result += sequence_list[i-1]
     return ''.join(new_result)
'''
def get_sequence(initial_position, final_position):
   content = ""
   with open("banana.txt") as f:
       content = f.readlines()
   content = [x.strip() for x in content
   print(content)
   return ""

def invert_sequence(sequence):
   return ''.join(reversed(sequence))

def get_reverse_nucleotide(sequence):
   reversed = sequence
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
    sequence_list = list(sequence)
    codon = ""
    receipe = ""
    found_initial_codon = False
    global middle_position
    for nucleotide in sequence_list:
        if len(codon) == CODON_SIZE:
            if not found_initial_codon:
                if codon in start_codons:
                    receipe += codon
                    codon = ""
                    found_initial_codon = True
                else:
                    codon = codon[1:]
            else:
                if codon in end_codons:
                    receipe += codon
                    break
                else:
                    receipe += codon[:1]
                    codon = codon[1:]
        if not found_initial_codon:
            middle_position += 1
        codon += nucleotide
    return receipe

def get_initial_codon_position(signal):
    position = (middle_position%3) + 1
    print("\nCodon Position: " + signal + position.__str__())

def show_amino(sequence):
   codon = ""
   sequence_list = list(sequence)
   first_time = True
   sys.stdout.write('Aminoácidos: ')
   for nucleotide in sequence_list:
       if len(codon) == CODON_SIZE:
           for amino_letter in amino_acids:
               for position in range(len(amino_acids[amino_letter])):
                   if codon == amino_acids[amino_letter][position]:
                       if codon in start_codons and first_time:
                           sys.stdout.write(amino_letter)
                           first_time = False
                       else:
                           sys.stdout.write(', '+amino_letter)
                       break
                       break
           codon = ""
       codon += nucleotide
   print("")


if __name__ == '__main__':
    print(get_sequence(initial_position, final_position))
    """print("A fita é negativa ou positiva? P / N")
    format_string = input()
    sequence = get_sequence(initial_position, final_position).lower()
    sequence = get_reverse_nucleotide(sequence)
    receipe = get_receipes(sequence)
    print(receipe)"""
