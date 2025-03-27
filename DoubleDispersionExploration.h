#ifndef DOUBLE_DISPERSION_EXPLORATION_H
#define DOUBLE_DISPERSION_EXPLORATION_H

#include "ExplorationFunction.h"

template <class Key>
class DoubleDispersionExploration : public ExplorationFunction<Key> {
  public:
    DoubleDispersionExploration(HashFunction<Key>& hash) : hash_{hash} {}; 
    unsigned operator()(const Key& key, unsigned attempt) const {
      return hash_(key, this->max) * attempt;
    }
  private: 
    HashFunction<Key>& hash_;
};

#endif 