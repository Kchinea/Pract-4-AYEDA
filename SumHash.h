#ifndef SUM_HASH_H_
#define SUM_HASH_H_

#include "HashFunction.h"

template<class Key>
class SumHash : public HashFunction<Key> {
  public:
    unsigned operator()(const Key& key, size_t table_size) const {
      int index = 0;
      for (int i = 0; i < key.size(); i++) {
        index += key[i];
      }
      return index % table_size;
    }
};

#endif  // SUMHASH_H_