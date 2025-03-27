#include "Nif.h"
#include <cmath>
#include <iostream>

NIF::NIF() {
  nif_ = rand() % max_digits;
}

NIF::NIF(long number) {
  nif_ = number % max_digits;
}

long NIF::operator[](int index) const {
  return (nif_ / static_cast<int>(std::pow(10, index))) % 10;
}


bool NIF::operator==(const NIF& number) const {
  return this->nif_ == number.nif_;
}

bool NIF::operator!=(const NIF& number) const {
  return this->nif_ != number.nif_;
}

bool NIF::operator<(const NIF& number) const {
  return this->nif_ < number.nif_;
}

bool NIF::operator>(const NIF& number) const {
  return this->nif_ > number.nif_;
}

long unsigned int NIF::size() const {
  return 8;
}

NIF::operator long() const {
  return this->nif_;
}

std::istream& operator>>(std::istream& is, NIF& nif) {
  is >> nif.nif_;
  return is;
}