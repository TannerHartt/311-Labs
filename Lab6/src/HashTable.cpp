// CSCI 311 - Spring 2023
// Lab 6 - Hash Table cpp
// Author: Carter Tillquist

#include <iostream>
#include <math.h>
#include "HashTable.h"

HashTable::HashTable(): size(11), numElements(0), p(31)
{
  table.resize(size);
}

HashTable::HashTable(int s, int mult): size(s), numElements(0), p(mult)
{
  table.resize(size);
}

int HashTable::getSize(){ return size; }
int HashTable::getNumElements(){ return numElements; }
int HashTable::getP(){ return p; }

void HashTable::printTable(){
  std::cout << "HASH TABLE CONTENTS" << std::endl;
  for (int i = 0; i < table.size(); i++){
    if (table[i].size() > 0){
      std::cout << i << ": ";
      for (int j = 0; j < table[i].size()-1; j++){
        std::cout << table[i][j] << ", ";
      }
      std::cout << table[i][table[i].size()-1] << std::endl;
    }
  }
}

int HashTable::search(std::string s) 
{
    int index = hash(s);

    for (size_t i = 0; i < table[index].size(); i++) 
    {
        if (table[index][i] == s) 
        {
          return index;
        }
    }

    return -1;
}

void HashTable::insert(std::string s)
{
    int index = hash(s);
    table[index].push_back(s);
    numElements++;
}

void HashTable::remove(std::string s) 
{
    int index = hash(s);
    for (auto iter = table[index].begin(); iter != table[index].end(); ++iter)
    {
        if (*iter == s) 
        {
            table[index].erase(iter);
            numElements--;
            break;
        }
    }
}

void HashTable::resize(int s) 
{
    std::vector<std::vector<std::string> > newTable(s);

    int old = size;
    size = s;
    std::vector<std::vector<std::string> > oldTable = table;
    table = newTable;

    numElements = 0;

    for (const auto& chaining : oldTable)
    {
        for (const std::string& s : chaining) 
        {
            insert(s);
        }
    }
}


int HashTable::hash(std::string s) 
{
    unsigned int hashVal = 0;
    unsigned int power = 1;

    for (char character : s) 
    {
        hashVal = (hashVal + (character) * power) % size;
        power = (power * p) % size;
    }

    return hashVal;
}


