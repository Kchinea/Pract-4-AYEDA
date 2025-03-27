#include <iostream>
#include <string>
#include "HashTable.h"
#include "Nif.h"
#include "Parser.h"

int main(int argc, char **argv) {
  Parser parser(argc, argv);
  if (!parser.IsValid()) {
    return EXIT_FAILURE;
  }

  unsigned table_size = parser.GetTableSize();
  unsigned block_size = parser.GetBlockSize();
  std::string hash_type = parser.GetHashType();
  std::string dispersion_func = parser.GetDispersionFunc();
  std::string exploration_func = parser.GetExplorationFunc();

  // Crear función de dispersión
  HashFunction<NIF> *hash_func = nullptr;
  if (dispersion_func == "module") {
    hash_func = new ModuleHash<NIF>();
  } else if (dispersion_func == "sum") {
    hash_func = new SumHash<NIF>();
  } else if (dispersion_func == "pseudorandom") {
    hash_func = new PseudoRandomHash<NIF>();
  }

  // Crear función de exploración
  ExplorationFunction<NIF> *exploration_func_ptr = nullptr;
  if (exploration_func == "lineal") {
    exploration_func_ptr = new LinealExploration<NIF>();
  } else if (exploration_func == "cuadratic") {
    exploration_func_ptr = new CuadraticExploration<NIF>();
  } else if (exploration_func == "doubledispersion") {
    exploration_func_ptr = new DoubleDispersionExploration<NIF>(*hash_func);
  } else if (exploration_func == "redispersion") {
    exploration_func_ptr = new RedispersionExploration<NIF>();
  }

  // Creación de la tabla hash
  if (hash_type == "open") {
    HashTable<NIF, DynamicSequence<NIF>>* table = new HashTable<NIF, DynamicSequence<NIF>>(table_size, hash_func, block_size);
    while (true) {
      std::cout << "Select an option:\n1. Insert\n2. Search\n3. Exit\n";
      int option;
      std::cin >> option;
      if (option == 1) {
        std::cout << "Insert the value (NIF): ";
        NIF key;
        std::cin >> key;
        table->Insert(key);
        std::cout << "Value has been inserted.\n";
      } else if (option == 2) {
        std::cout << "Insert the value (NIF): ";
        long nif_value;
        std::cin >> nif_value;
        NIF key(nif_value);
        bool result = table->Search(key);
      } else if (option == 3) {
        break;
      } else {
        std::cout << "Error, not valid option.\n";
      }
    }
  } else if (hash_type == "close") {
    HashTable<NIF>* table = new HashTable<NIF>(table_size, hash_func, exploration_func_ptr, block_size);
    while (true) {
      std::cout << "Select an option:\n1. Insert\n2. Search\n3. Exit\n";
      int option;
      std::cin >> option;
      if (option == 1) {
        std::cout << "Insert the value (NIF): ";
        NIF key;
        std::cin >> key;
        table->Insert(key);
        std::cout << "Value has been inserted.\n";
      } else if (option == 2) {
        std::cout << "Insert the value (NIF): ";
        long nif_value;
        std::cin >> nif_value;
        NIF key(nif_value);
        bool result = table->Search(key);
      } else if (option == 3) {
        break;
      } else {
        std::cout << "Error, not valid option.\n";
      }
    }
  }
  return 0;
}
