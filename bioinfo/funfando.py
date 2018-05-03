#!/usr/bin/env python
# -*- coding: utf-8 -*
import sys
CODON_SIZE = 3
initial_position = 3462111
final_position = 3463457
middle_position = initial_position
start_codons = ['atg', 'gtg']
end_codons = ['taa', 'tag', 'tga']

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

def get_sequence(initial_position, final_position):
  text = ""
  result = ""
  print("A fita é negativa ou positiva? P / N")
  format_string = input()
  file = open("real.txt", "r")
  for line in file:
      text += line
  result = text.replace("\n", "")
  result_list = list(result)
  list_char = ""
  for i in range(initial_position, final_position+1):
      list_char += result_list[i-1]
  retorno = ''.join(list_char)
  if format_string.lower() == "n":
    result = invert_sequence(retorno)
    retorno = get_reverse_nucleotide(result)
  return retorno

def invert_sequence(sequence):
 return ''.join(reversed(sequence))

def get_reverse_nucleotide(sequence):
 result = ""
 sequence = sequence.lower()
 for nucleotideo in sequence:
     if (nucleotideo == 'a'):
         result += 't'
     elif (nucleotideo == 't'):
         result += 'a'
     elif (nucleotideo == 'g'):
         result += 'c'
     elif (nucleotideo == 'c'):
         result += 'g'
 return result

def get_receipes(sequence):
  sequence_list = list(sequence)
  codon = ""
  receipe = ""
  for nucleotide in sequence_list:
      codon += nucleotide
      if len(codon) == CODON_SIZE:
          receipe += codon
          if codon in end_codons:
              break
          codon = ""
  return receipe

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
                          if amino_letter != "Stop":
                              sys.stdout.write(', '+amino_letter)
                     break
                     break
         codon = ""
     codon += nucleotide
 print("")

def show_receipe(receipe):
    print("Receita: "+ receipe)

if __name__ == '__main__':
  sequence = get_sequence(initial_position, final_position).lower()
  receipe = get_receipes(sequence)
  show_receipe(receipe)
  show_amino(receipe)