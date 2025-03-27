#ifndef LINEAL_EXPLORATION_H
#define LINEAL_EXPLORATION_H

#include "ExplorationFunction.h"

template <class Key>
class LinealExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& key, unsigned intent) const {
      return intent;
    }
};

#endif  // LINEAL_EXPLORATION_H