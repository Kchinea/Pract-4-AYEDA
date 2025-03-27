#ifndef MODULO_Hash_H_
#define MODULO_Hash_H_

#include "HashFunction.h"

template <class Key>
class ModuleHash : public HashFunction<Key> {
  public:
    unsigned operator()(const Key& key, size_t table_size) const {
      return static_cast<long>(key) % table_size;
    }
};

#endif