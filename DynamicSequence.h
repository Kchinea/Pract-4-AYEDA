#ifndef DYNAMIC_SEQUENCE_H_
#define DYNAMIC_SEQUENCE_H_

#include <list>
#include "Sequence.h"

template <class Key>
class DynamicSequence : public Sequence<Key> {
  public:
    bool Search(const Key&) const;
    bool Insert(const Key&);
 
  private:
    std::list<Key> data_;
};

template<class Key>
bool DynamicSequence<Key>::Search(const Key& key) const {
  for (const Key& current_key : data_) {
    if (current_key == key) return true;
  }
  return false;
}

template<class Key>
bool DynamicSequence<Key>::Insert(const Key& key) {
  if (Search(key)) return false;
  data_.push_back(key);
  return true;
}

#endif 