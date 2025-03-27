#ifndef RANDOM_HASH_H
#define RANDOM_HASH_H

#include "HashFunction.h"

template<class Key>
class PseudoRandomHash : public HashFunction<Key> {
  public:
    unsigned operator()(const Key& key, size_t table_size) const {
      srand(static_cast<long>(key));
      return rand() % table_size;
    }
};

#endif  