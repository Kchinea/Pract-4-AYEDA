#ifndef HASH_FUNCTION_H_
#define HASH_FUNCTION_H_

#include <cstdlib>


template <class Key>
class HashFunction {
 public:
  virtual unsigned operator()(const Key&, long unsigned int table_size) const = 0;
  virtual ~HashFunction() = default;
};
#endif  // HASH_FUNCTION_H_