#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "HashTable.h"
#include "Nif.h"

class Menu {
  public:
    static void Run(HashTable<NIF, DynamicSequence<NIF>>* table);
    static void Run(HashTable<NIF>* table);

  private:
    template <typename TableType>
    static void RunMenu(TableType* table);

    template <typename TableType>
    static void InsertValue(TableType* table);

    template <typename TableType>
    static void SearchValue(TableType* table);
};

#endif
