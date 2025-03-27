#ifndef HASHTABLEBUILDER_H
#define HASHTABLEBUILDER_H

#include "HashTable.h"
#include "Nif.h"
#include "Parser.h"

class HashTableBuilder {
  public:
    static HashTable<NIF, DynamicSequence<NIF>>* BuildOpenHashTable(const Parser& parser);
    static HashTable<NIF>* BuildClosedHashTable(const Parser& parser);

  private:
    static HashFunction<NIF>* CreateHashFunction(const std::string& type);
    static ExplorationFunction<NIF>* CreateExplorationFunction(const std::string& type, HashFunction<NIF>* hash_func);
};

#endif
