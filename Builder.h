#ifndef HASHTABLEBUILDER_H
#define HASHTABLEBUILDER_H

#include "HashTable.h"
#include "Nif.h"
#include "Parser.h"

template <class Key>
class HashTableBuilder {
  public:
    static HashTable<Key, DynamicSequence<Key>>* BuildOpenHashTable(const Parser& parser);
    static HashTable<Key>* BuildClosedHashTable(const Parser& parser);

  private:
    static HashFunction<Key>* CreateHashFunction(const std::string& type);
    static ExplorationFunction<Key>* CreateExplorationFunction(const std::string& type, HashFunction<NIF>* hash_func);
};

#endif
