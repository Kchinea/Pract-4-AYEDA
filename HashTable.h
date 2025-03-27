#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "HashFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "CuadraticExploration.h"
#include "DoubleDispersionExploration.h"
#include "LinealExploration.h"
#include "RedispersionExploration.h"
#include "ModuloHash.h"
#include "RandomHash.h"
#include "SumHash.h"
#include "StaticSequence.h"
#include "DynamicSequence.h"

#include <iostream>
#include <vector>

template <class Key, class Container = StaticSequence<Key>>
class HashTable {
  public:
    HashTable(unsigned, HashFunction<Key>*, ExplorationFunction<Key>*, unsigned);
    ~HashTable();
    bool Search(const Key&) const;
    void Insert(const Key&);

  private:
    unsigned table_size_;
    unsigned block_size_;
    HashFunction<Key>* fd_;
    ExplorationFunction<Key>* fe_;
    Container** table_;
};

template <class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned table_size, HashFunction<Key>* fd, ExplorationFunction<Key>* fe, unsigned block_size) :
  table_size_{table_size}, fd_{fd}, fe_{fe}, block_size_{block_size} {
  table_ = new Container*[table_size_]; 
  for (unsigned i = 0; i < table_size; ++i) {
    table_[i] = new Container{block_size}; 
  }
}

template <class Key, class Container>
HashTable<Key, Container>::~HashTable() {
  for (unsigned i = 0; i < table_size_; ++i) {
    delete table_[i];
  }
  delete[] table_; 
  delete fd_;
  delete fe_;
}

template <class Key, class Container>
bool HashTable<Key, Container>::Search(const Key& key) const { 
  unsigned index = fd_->operator()(key, table_size_);

  if (table_[index]->Search(key)) {
    std::cout << "Finded " << key << " at " << index << std::endl;
    return true;
  }

  const int MAX_INTENTS = table_size_;
  for (unsigned i = 1; i < MAX_INTENTS; ++i) {
    unsigned exploration_value = fe_->operator()(key, i);
    unsigned auxiliar_index = (index + exploration_value) % table_size_; 
    if (table_[auxiliar_index]->Search(key)) {
      std::cout << "Finded " << key << " at " << auxiliar_index << std::endl;
      return true;
    }
  }
  std::cout << "Not found " << key << std::endl;
  return false;
}

template <class Key, class Container>
void HashTable<Key, Container>::Insert(const Key& key) {
  unsigned index = fd_->operator()(key, table_size_);
  
  if (this->Search(key)) return;
  if (table_[index]->Insert(key)) {
    std::cout << "Inserted " << key << " at " << index << std::endl;
    return;
  }
  const int MAX = table_size_;
  for (unsigned i = 1; i < MAX; ++i) {
    unsigned exploration_value = fe_->operator()(key, i);
    unsigned auxiliar_index = (index + exploration_value) % table_size_; 
    if (table_[auxiliar_index]->Insert(key)) {
      std::cout << "Inserted " << key << " at " << auxiliar_index << std::endl;
      return;
    }
  }
  return;
}

template <class Key>
class HashTable<Key, DynamicSequence<Key>> {
  public:
    HashTable(unsigned, HashFunction<Key>*, unsigned);
    ~HashTable();
    bool Search(const Key&) const;
    void Insert(const Key&);

  private:
  HashFunction<Key>* fd_;
  DynamicSequence<Key>* table_; 
    unsigned table_size_;
};

template<class Key>
HashTable<Key, DynamicSequence<Key>>::HashTable(unsigned table_size, HashFunction<Key>* fd, unsigned block_size) : 
  table_size_{table_size}, fd_{fd} {
  table_ = new DynamicSequence<Key>[table_size];  
}

template<class Key>
HashTable<Key, DynamicSequence<Key>>::~HashTable() {
  delete[] table_; 
  delete fd_;
}

template<class Key>
bool HashTable<Key, DynamicSequence<Key>>::Search(const Key& key) const {
  unsigned index = fd_->operator()(key, table_size_);
  if (table_[index].Search(key)) {
    std::cout << "Finded " << key << " at " << index << std::endl;
    return true;
  }
    std::cout << "Not found " << key << std::endl;
  return false;
}

template<class Key>
void HashTable<Key, DynamicSequence<Key>>::Insert(const Key& key) {
  unsigned index = fd_->operator()(key, table_size_);
  if (table_[index].Insert(key)) {
    std::cout << "Inserted " << key << " at " << index << std::endl;
  }
  return;
}

#endif