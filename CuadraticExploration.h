#ifndef CUADRATIC_EXPLORATION_H
#define CUADRATIC_EXPLORATION_H

#include "ExplorationFunction.h"

template <class Key>
class CuadraticExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& key, unsigned attempt) const {
      return attempt * attempt;
    }
};
#endif 