#include "Builder.h"

// Crea una tabla hash abierta
HashTable<NIF, DynamicSequence<NIF>>* HashTableBuilder::BuildOpenHashTable(const Parser& parser) {
  HashFunction<NIF>* hash_func = CreateHashFunction(parser.GetDispersionFunc());
  return new HashTable<NIF, DynamicSequence<NIF>>(parser.GetTableSize(), hash_func, parser.GetBlockSize());
}

// Crea una tabla hash cerrada
HashTable<NIF>* HashTableBuilder::BuildClosedHashTable(const Parser& parser) {
  HashFunction<NIF>* hash_func = CreateHashFunction(parser.GetDispersionFunc());
  ExplorationFunction<NIF>* exploration_func = CreateExplorationFunction(parser.GetExplorationFunc(), hash_func);
  return new HashTable<NIF>(parser.GetTableSize(), hash_func, exploration_func, parser.GetBlockSize());
}

// Crea la función de dispersión adecuada
HashFunction<NIF>* HashTableBuilder::CreateHashFunction(const std::string& type) {
  if (type == "module") return new ModuleHash<NIF>();
  if (type == "sum") return new SumHash<NIF>();
  if (type == "pseudorandom") return new PseudoRandomHash<NIF>();
  return nullptr;
}

// Crea la función de exploración adecuada
ExplorationFunction<NIF>* HashTableBuilder::CreateExplorationFunction(const std::string& type, HashFunction<NIF>* hash_func) {
  if (type == "lineal") return new LinealExploration<NIF>();
  if (type == "cuadratic") return new CuadraticExploration<NIF>();
  if (type == "doubledispersion") return new DoubleDispersionExploration<NIF>(*hash_func);
  if (type == "redispersion") return new RedispersionExploration<NIF>();
  return nullptr;
}
