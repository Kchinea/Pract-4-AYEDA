#include "Menu.h"

// Ejecuta el menú para tablas abiertas
template <class Key>
void Menu<Key>::Run(HashTable<Key, DynamicSequence<NIF>>* table) {
    RunMenu(table);
}

// Ejecuta el menú para tablas cerradas
template <class Key>
void Menu<Key>::Run(HashTable<Key>* table) {
    RunMenu(table);
}

// Método privado que maneja la lógica del menú
template <typename TableType>
void Menu<TableType>::RunMenu(TableType* table) {
    while (true) {
        std::cout << "Select an option:\n1. Insert\n2. Search\n3. Exit\n";
        int option;
        std::cin >> option;
        if (option == 1) {
            InsertValue(table);
        } else if (option == 2) {
            SearchValue(table);
        } else if (option == 3) {
            break;
        } else {
            std::cout << "Error, not valid option.\n";
        }
    }
}

// Inserta un valor en la tabla
template <typename TableType>
void Menu<TableType>::InsertValue(TableType* table) {
    std::cout << "Insert the value (NIF, Persona or Alumno): ";
    Persona key;
    std::cin >> key;
    table->Insert(key);
    std::cout << "Value has been inserted.\n";
}

// Busca un valor en la tabla
template <typename TableType>
void Menu<TableType>::SearchValue(TableType* table) {
    std::cout << "Insert the value (NIF): ";
    std::string nif_value;
    std::cin >> nif_value;
    Persona key(nif_value);
    bool result = table->Search(key);
    if (result) {
        std::cout << "Value found.\n";
    } else {
        std::cout << "Value not found.\n";
    }
}


