#!/usr/bin/env python
# -*- coding: utf-8 -*

import sys

normal_strand = ""
reverse_strand = ""

def create_strands():
    global normal_strand
    global reverse_strand

    file = open("sequence.txt", "r")
    filed_reversed = open("reversegenoma.txt", "w")
    normal_strand = file.read().replace("\n", "")
    reverse_strand = normal_strand[::-1]

def get_read(initial_position, final_position, isNegative):
  strand = normal_strand
  read = ""

  if isNegative:
      strand = reverse_strand
  #transform string into list to get each char    
  strand = list(strand)  
  #searching for desired read  
  for i in range(initial_position, final_position+1):
      read += strand[i-1]
  #transforming list into string     
  read = ''.join(read)

  if isNegative:
    read = swap_nucleotide(read)

  return read.lower()

def swap_nucleotide(sequence):
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

def longest_common_substring(str1, str2):
  matrix = [[0]*(1+len(str2)) for i in range(1+len(str1))]
  longest, x_longest = 0, 0
  for x in range(1,1+len(str1)):
    for y in range(1,1+len(str2)):
        if str1[x-1] == str2[y-1]:
            matrix[x][y] = matrix[x-1][y-1] + 1
            if matrix[x][y] > longest:
                longest = matrix[x][y]
                x_longest = x
        else:
            matrix[x][y] = 0
  return str1[x_longest-longest: x_longest]

def find_match(str1, str2, min_common):

    contig = str1    
    match = False
   
    # Fist conditions - If it is the same or it's contained in each other
    if str1 == str2:
        contig = str1
    elif str1 in str2:
        match = True
        contig = str2
    elif str2 in str1:
        contig = str1
    else:
        size1 = len(str1)
        size2 = len(str2)
        ref = ""
        slide = ""

        if size1 < size2:
            ref = str2
            slide = str1
        else:
            ref = str1
            slide = str2

        #get the longgest common substring
        longgest_common_substring = longest_common_substring(ref, slide)    

        if len(longgest_common_substring) >= min_common:
            end_of_ref = ref.split(longgest_common_substring)[1] #end after common part
            start_of_ref = ref.split(longgest_common_substring)[0] #start before common part

            end_of_slide = slide.split(longgest_common_substring)[1] #end after common part
            start_of_slide = slide.split(longgest_common_substring)[0] #start before common part

            if (start_of_slide != "" and end_of_slide != ""):#that's no way to overleap, common string is in middle
                contig = contig
                match = False
            elif end_of_ref == "":
                if (start_of_slide == ""):
                    contig = ref + end_of_slide
                    match = True
                else:#can't overleap
                    contig = contig
                    match = False
            elif start_of_ref == "":
                if (end_of_slide == ""):
                    contig = start_of_slide + ref
                    match = True
                else:#can't overleap
                    contig = contig
                    match = False
            else:#can't overleap
                match = False
        else:
            match = False

    return contig, match

def align_sequences(min_bases, contigs_num):
    #Get initial read
    contigs = 0
    with open('shotguns.txt') as f:
        lines = f.readlines()
        line_number, first_position, last_position, strip_type  = [int(x) for x in lines[0].split()]
        seed_read_position = line_number
    
        if strip_type == -1:
            seed_read = get_read(first_position, last_position, True)
        else:
            seed_read = get_read(first_position, last_position, False)     
        print("Seed position: "+str(seed_read_position)+" Seed: "+seed_read)

        #startup variables
        free_reads_total = len(lines)
        contig_list = []
        contig_list.append(seed_read)
        contig_of_read = [0] * len(lines)

        #Run until there are avaliable reads
        while contigs < contigs_num and free_reads_total > 0:
            #Get next seed
            if contigs > 0:
                for i in range(1, len(lines)):
                    line = lines[i]
                    line_number, first_position, last_position, strip_type  = [int(x) for x in line.split()]
                    if contig_of_read[line_number-1] == 0:# if is avaliable
                        if strip_type == -1: #negative one
                            contig_list[contigs] = get_read(first_position, last_position, True)
                        else:
                            contig_list[contigs] = get_read(first_position, last_position, False)
                        break

            for i in range(1, len(lines)):
                if contig_of_read[i] <= 0:
                    line = lines[i]
                    line_number, first_position, last_position, strip_type  = [int(x) for x in line.split()]
                    current_read = ""
                    if strip_type == -1:#negative one
                        current_read = get_read(first_position, last_position, True)
                    else:
                        current_read = get_read(first_position, last_position, False)

                    previous_contig = contig_list[contigs]
                    returned_contig, match = find_match(contig_list[contigs], current_read, min_bases)
                    contig_list[contigs] = returned_contig

                    if match:
                        print("seed "+str(seed_read_position)+" found read "+str(line_number)+"\n")
                        print("Previous contig: "+previous_contig)
                        print("Current Read: "+ current_read)
                        print("Contig: "+ returned_contig+"\n")
                        contig_of_read[i] = 1
                        free_reads_total -= 1

            contigs += 1

    return contig_list

if __name__ == '__main__':
  #Moving strands to memory  
  create_strands()  
  #Get user params
  print("Qual o número mínimo de bases a serem comparadas? ")
  min_bases = int(input())
  print("Quantos contigs deseja procurar?")
  contigs_num = int(input()) 
   
  contig_list = align_sequences(min_bases, contigs_num)  
    
  for i in range(0, len(contig_list)):
    print("Contig "+str(i+1)+": "+ contig_list[i])