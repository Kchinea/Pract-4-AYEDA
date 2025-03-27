#include "Builder.h"

// Crea una tabla hash abierta
template <class Key>
HashTable<Key, DynamicSequence<Key>>* HashTableBuilder::BuildOpenHashTable(const Parser& parser) {
  HashFunction<Key>* hash_func = CreateHashFunction(parser.GetDispersionFunc());
  return new HashTable<Key, DynamicSequence<Key>>(parser.GetTableSize(), hash_func, parser.GetBlockSize());
}

// Crea una tabla hash cerrada
template <class Key>
HashTable<Key>* HashTableBuilder::BuildClosedHashTable(const Parser& parser) {
  HashFunction<Key>* hash_func = CreateHashFunction(parser.GetDispersionFunc());
  ExplorationFunction<Key>* exploration_func = CreateExplorationFunction(parser.GetExplorationFunc(), hash_func);
  return new HashTable<Key>(parser.GetTableSize(), hash_func, exploration_func, parser.GetBlockSize());
}

// Crea la función de dispersión adecuada
template <class Key>
HashFunction<Key>* HashTableBuilder::CreateHashFunction(const std::string& type) {
  if (type == "module") return new ModuleHash<Key>();
  if (type == "sum") return new SumHash<Key>();
  if (type == "pseudorandom") return new PseudoRandomHash<Key>();
  return nullptr;
}

// Crea la función de exploración adecuada
template <class Key>
ExplorationFunction<Key>* HashTableBuilder::CreateExplorationFunction(const std::string& type, HashFunction<Key>* hash_func) {
  if (type == "lineal") return new LinealExploration<Key>();
  if (type == "cuadratic") return new CuadraticExploration<Key>();
  if (type == "doubledispersion") return new DoubleDispersionExploration<Key>(*hash_func);
  if (type == "redispersion") return new RedispersionExploration<Key>();
  return nullptr;
}
