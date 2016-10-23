#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <QDebug>

using namespace std;

// Compress a string to a list of output symbols.
// The result will be written to the output iterator
// starting at "result"; the final iterator is returned.

enum {
    emptyPrefix = -1 // empty prefix for ASCII characters
};

typedef struct DictNode {
  int prefix; // prefix for byte > 255
  char character; // the last byte of the string
  char wc[50];
  struct DictNode *next;
}CompleteDictionary;

CompleteDictionary *dict, *tail;

void dictionaryInit();
void appendNode(struct DictNode *node);
void dictionaryAdd(int prefix, std::string wc);
void dictionaryDestroy(ofstream &dicionario_file);
void saveDictionary(ofstream &dicionario_file);

void saveCompress(ofstream &compress_file, std::vector<int> compressed){
  for (std::vector<int>::iterator i = compressed.begin(); i != compressed.end(); ++i){
    compress_file << *i << " ";
  }
}

void saveDecompress(ofstream &decompress_file, std::string decompressed){
  decompress_file << decompressed;
}

void saveDictionary(ofstream &dicionario_file) {
  if (dict->character == '\0')
  {
    qDebug()        << "Prefixo: " << dict->prefix << " " << "Caracter: sem sinal gráfico";
    dicionario_file << "Prefixo: " << dict->prefix << " " << "Caracter: sem sinal gráfico" << std::endl;
  }
  else if (dict->prefix > 256)
  {
    qDebug()        << "Prefixo: " << dict->prefix << " " << QString::fromStdString(dict->wc);
    dicionario_file << "Prefixo: " << dict->prefix << " " << dict->wc << std::endl;
  }
  else
  {
    qDebug()        << "Prefixo: " << dict->prefix << " " << dict->character;
    dicionario_file << "Prefixo: " << dict->prefix << " " << dict->character << std::endl;
  }
}

void dictionaryInit() {
    int i;
    struct DictNode *node;
    for (i = 0; i <= 256; i++) { // ASCII
        node = (struct DictNode *)malloc(sizeof(struct DictNode));
        node->prefix = i;
        if (i < 32 || i > 126)node->character = '\0';
        else node->character = (char) i;
        appendNode(node);
    }
}

// add prefix + character to the dictionary
void dictionaryAdd(int prefix, string wc) {
    struct DictNode *node;
    node = (struct DictNode *)malloc(sizeof(struct DictNode));
    node->prefix = prefix;
    strcpy(node->wc, wc.c_str());
    node->character = 'N';
    //printf("\n(%i) = (%i) + (%i)\n", node->value, node->prefix, node->character);
    appendNode(node);
}

// add node to the list
void appendNode(struct DictNode *node) {
    if (dict != NULL) tail->next = node;
    else dict = node;
    tail = node;
    node->next = NULL;
}

void dictionaryDestroy(ofstream &dicionario_file) {
    while (dict != NULL) {
        saveDictionary(dicionario_file);
        dict = dict->next; /* the head now links to the next element */
    }
}

template <typename Iterator>
Iterator compress(const std::string &uncompressed, Iterator result) {
  // Build the dictionary.
  int dictSize = 256;
  dictionaryInit();
  std::map<std::string,int> dictionary;
  for (int i = 0; i < 256; i++){
    dictionary[std::string(1, i)] = i;
  }

  std::string w;
  for (std::string::const_iterator it = uncompressed.begin(); it != uncompressed.end(); ++it) {
    char c = *it;
    std::string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else {
      *result++ = dictionary[w];
      // Add wc to the dictionary.
      dictionary[wc] = dictSize++;
      w = std::string(1, c);
      dictionaryAdd(dictSize, wc);
    }
  }

  // Output the code for w.
  if (!w.empty())
    *result++ = dictionary[w];
  return result;
}

// Decompress a list of output ks to a string.
// "begin" and "end" must form a valid range of ints
template <typename Iterator>
std::string decompress(Iterator begin, Iterator end) {
  // Build the dictionary.
  int dictSize = 256;
  std::map<int,std::string> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[i] = std::string(1, i);

  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ; begin != end; begin++) {
    int k = *begin;
    if (dictionary.count(k))
      entry = dictionary[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";

    result += entry;

    // Add w+entry[0] to the dictionary.
    dictionary[dictSize++] = w + entry[0];

    w = entry;
  }
  return result;
}
