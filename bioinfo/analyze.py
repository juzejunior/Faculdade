#!/usr/bin/env python
# -*- coding: utf-8 -*

import sys

CODON_SIZE = 3
PROMOTOR_BACKWARD = 35
initial_position = 4712105
final_position = 4713745
middle_position = initial_position
start_codons = ['atg', 'gtg']
end_codons = ['taa', 'tag', 'tga']
format_string = ""

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

def get_all_sequence():
    text = ""
    result = ""
    file = open("sequence.txt", "r")

    for line in file:
        text += line
    result = text.replace("\n", "")
    result_list = list(result)

    if format_string.lower() == "n":
        result = invert_sequence(result_list)
        result = get_reverse_nucleotide(result)
    return result.lower()

def get_sequence(initial_position, final_position):
  text = ""
  result = ""
  print("A fita é negativa ou positiva? P / N")
  format_string = input()
  print("Qual o intervalo para encontrar o promotor?")
  PROMOTOR_BACKWARD = int(input())
  file = open("sequence.txt", "r")

  for line in file:
      text += line
  result = text.replace("\n", "")
  result_list = list(result)
  list_char = ""

  for i in range(initial_position, final_position+1):
      list_char += result_list[i-1]
  some_list_char = ""
  
  for i in range(initial_position - PROMOTOR_BACKWARD, initial_position):
      some_list_char += result_list[i-1]
  promotion_region = ''.join(some_list_char)

  retorno = ''.join(list_char)

  if format_string.lower() == "n":
    result = invert_sequence(retorno)
    retorno = get_reverse_nucleotide(result)

  return retorno.lower(), promotion_region.lower()

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
 print("\n")

def show_receipe(receipe):
    print("Receita: "+ receipe+"\n")

def find_promotor(sequence):
    cont = 0
    promotor = ""
    possible_promotors = []
    for char in sequence:
        if char == 't' or char == 'a':
            promotor += char
        else:
            if promotor != "":
                possible_promotors.append(promotor)
            promotor = ""
    promotor = max(possible_promotors, key=len)
    equals_promo = []
    # verificar quantidades de t e a depois dividir o numero de a por ts e  pegar o maior: 2 maior qqt de silaba TA
    for promo in possible_promotors:
        if promo != promotor:
            if len(promo) == len(promotor):
                equals_promo.append(promo)
    
    promos_with_count_tas = []
    
    if len(equals_promo) > 0 :
        equals_promo.append(promotor)
        total_ta = 0
        new_promo = ""
        promos_with_count_tas = []
        for promo in equals_promo:
            if total_ta <= promo.count("ta"):
                total_ta = promo.count("ta")
                new_promo = promo
                promos_with_count_tas.append(new_promo)
            promotor = new_promo
    #make a/t verification and get position 
    promos_by_t = []
    
    if len(promos_with_count_tas) > 1:
        sum_a_by_t = 0
        for promo in promos_with_count_tas:
            current = promo.count("a") / promo.count("t") 
            if sum_a_by_t <= current:
                sum_a_by_t = current
                promos_by_t.append(promo)
            promotor = promo 
    if len(promos_by_t) > 0:
        return promos_by_t
    else:  
        promotors = []
        promotors.append(promotor)
        return promotors

def find_restriction_sequence(sequence):
    restriction_sequence = "GAATTC" #input("SEQUENCIA DE RESTRICAO: ")
    restriction_sequence = restriction_sequence.lower()
    count = position = found_restriction = fragment_position = gene_position = 0
    fragments = []
    initial = 1

    for base in sequence:
        position += 1
        if base == restriction_sequence[count]:
            if restriction_sequence.__len__() - 1 == count:
                final = position - (restriction_sequence.__len__() - 1)
                fragments.append([initial.__str__(), final.__str__()])
                found_restriction += 1
                count = 0
                fragment_position += 1
                if (initial <= initial_position and final >= final_position):
                    gene_position = fragment_position
                initial = position - (restriction_sequence.__len__() - 2)
            else :
                count += 1
        else:
            if (base == restriction_sequence[0]): count = 1
            else: count = 0

    print("NUMERO DE FRAGMENTOS DE RESTRIÇÃO: " + fragments.__len__().__str__())
    print("O FRAGMENTO " + gene_position.__str__() +  " CONTEM O GENE EM ESTUDO")
    print("LISTA DE FRAGMENTOS \n")
    for initial, final in fragments:
        print(initial + ":" + final)


if __name__ == '__main__':
  sequence, promotion_region = get_sequence(initial_position, final_position)
  receipe = get_receipes(sequence)
  show_receipe(receipe)
  show_amino(receipe)
  print("REGIAO: "+promotion_region)
  promotors = find_promotor(promotion_region)
  if len(promotors) == 1: 
    print("PROMOTOR: "+ promotors[0])
  else:
    print("PROMOTORES: ")
    for promo in promotors:
        print(promo+", ")
  sequence = get_all_sequence()
  print("NUMERO DE BASES NA SEQUENCIA: " + sequence.__len__().__str__())
  find_restriction_sequence(sequence)
   

