// #include "Nif.h"
// #include <cmath>
// #include <iostream>

// NIF::NIF() {
//   nif_ = rand() % max_digits;
// }

// NIF::NIF(long number) {
//   nif_ = number % max_digits;
// }

// long NIF::operator[](int index) const {
//   return (nif_ / static_cast<int>(std::pow(10, index))) % 10;
// }


// bool NIF::operator==(const NIF& number) const {
//   return this->nif_ == number.nif_;
// }

// bool NIF::operator!=(const NIF& number) const {
//   return this->nif_ != number.nif_;
// }

// bool NIF::operator<(const NIF& number) const {
//   return this->nif_ < number.nif_;
// }

// bool NIF::operator>(const NIF& number) const {
//   return this->nif_ > number.nif_;
// }

// long unsigned int NIF::size() const {
//   return 8;
// }

// NIF::operator long() const {
//   return this->nif_;
// }

// std::istream& operator>>(std::istream& is, NIF& nif) {
//   is >> nif.nif_;
//   return is;
// }

#include "Nif.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

NIF::NIF() : nif_number_(0) {}

NIF::NIF(const std::string& nif_str) {
  if (nif_str.length() != 9) { 
    throw std::invalid_argument("Invalid NIF length");
  }
  nif_number_ = 0;
  for (int i = 0; i < 8; ++i) {
    if (nif_str[i] < '0' || nif_str[i] > '9') {
      throw std::invalid_argument("Invalid digit in NIF");
    }
    nif_number_ = nif_number_ * 10 + (nif_str[i] - '0');
  }
  if (nif_str[8] < 'A' || nif_str[8] > 'Z') {
    throw std::invalid_argument("Invalid letter in NIF");
  }
  nif_number_ = nif_number_ * 100 + static_cast<int>(nif_str[8]);
}

long NIF::getNumber() const {
    return nif_number_;
}

bool NIF::operator==(const NIF& number) const {
    return this->nif_number_ == number.nif_number_;
}

bool NIF::operator!=(const NIF& number) const {
    return !(*this == number);
}

bool NIF::operator<(const NIF& number) const {
    return this->nif_number_ < number.nif_number_;
}

bool NIF::operator>(const NIF& number) const {
    return this->nif_number_ > number.nif_number_;
}

long NIF::operator[](int index) const {
  return (this->nif_number_ / static_cast<int>(std::pow(10, index))) % 10;
}

long unsigned int NIF::size() const{
    return 10;
}

NIF::operator long() const {
    return this->nif_number_;
}

std::istream& operator>>(std::istream& is, NIF& nif) {
  std::string input;
  is >> input;
  try {
      nif = NIF(input);
  } catch (const std::invalid_argument& e) {
      is.setstate(std::ios::failbit);
  }
  return is;
}