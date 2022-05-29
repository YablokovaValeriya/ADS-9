// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string>TREE;
  std::string word;
  std::string line;

  if (!file) {
    std::cout << "File error!" << std::endl;
    return TREE;
  }
  while (file) {
    file >> word;
    int symbol = 0, k = 0;
    while (symbol < word.size()) {
      while ((word[symbol] >= 'a' && word[symbol] <= 'z') || (word[symbol] >= 'A' && word[symbol] <= 'Z') && (symbol < word.size())) {
        if (word[symbol] >= 'A' && word[symbol] <= 'Z') {
          word[symbol] += 32;
          line += word[symbol];
          symbol++;
          k++;
        }
        if (k != 0) {
          TREE.add(line);
          line = "";
        } else {
          symbol++;
        }
      }
    }
    file.close();
    return TREE;
  }
}
