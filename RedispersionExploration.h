#ifndef REDISPERSIONEXPLORATION_H
#define REDISPERSIONEXPLORATION_H

#include "ExplorationFunction.h"

template <class Key>
class RedispersionExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& key, unsigned attempt) const {
      srand(key);
      for (int i = 0; i < attempt - 1; i++) 
        rand();
      return rand();
    }
};

#endif