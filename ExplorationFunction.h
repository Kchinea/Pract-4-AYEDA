#ifndef EXPLORATION_FUNCTION_H_
#define EXPLORATION_FUNCTION_H_


#include "HashFunction.h"

template <class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key&, unsigned) const = 0;
  virtual ~ExplorationFunction() = default;
 protected:
  const long max = 100000000000000000;
};

#endif