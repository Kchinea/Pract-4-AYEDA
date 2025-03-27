#include "Persona.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

Persona::Persona() : nif_number_(0) , name_(""), last_name_("") {}

Persona::Persona(const std::string& nif_str, std::string name, std::string lastName) {
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
  name_ = name;
  last_name_ = last_name_;
}

long Persona::getNumber() const {
  return nif_number_;
}

bool Persona::operator==(const Persona& number) const {
    return (this->nif_number_ == number.nif_number_);
}

bool Persona::operator!=(const Persona& number) const {
    return !(*this == number);
}

bool Persona::operator<(const Persona& number) const {
    return this->nif_number_ < number.nif_number_;
}

bool Persona::operator>(const Persona& number) const {
    return this->nif_number_ > number.nif_number_;
}

long Persona::operator[](int index) const {
  return (this->nif_number_ / static_cast<int>(std::pow(10, index))) % 10;
}

long unsigned int Persona::size() const{
  return 10;
}

Persona::operator long() const {
  return this->nif_number_;
}

std::istream& operator>>(std::istream& is, Persona& nif) {
  std::string numberNif, name, lastName;
  is >> numberNif >> name >> lastName;
  nif = Persona(numberNif, name, lastName);
  return is;
}