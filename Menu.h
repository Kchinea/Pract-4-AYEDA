#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "HashTable.h"
#include "Nif.h"
#include "Persona.h"
#include "Alumno.h"

template <class Key>
class Menu {
  public:
    static void Run(HashTable<Key, DynamicSequence<Key>>* table);
    static void Run(HashTable<Key>* table);

  private:
    template <typename TableType>
    static void RunMenu(TableType* table);

    template <typename TableType>
    static void InsertValue(TableType* table);

    template <typename TableType>
    static void SearchValue(TableType* table);
};

#endif
