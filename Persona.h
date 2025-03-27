#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>

class Persona {
  public:
    Persona();
    Persona(const std::string& nif_str, std::string name, std::string lastName);
    
    long getNumber() const;
    
    long operator[](int) const;
    bool operator==(const Persona&) const;
    bool operator!=(const Persona&) const;
    bool operator<(const Persona&) const;
    bool operator>(const Persona&) const;
    long unsigned int size() const;
    
    operator long() const;
    
    friend std::istream& operator>>(std::istream& is, Persona& nif);

  private:
    long nif_number_;
    std::string name_;
    std::string last_name_;
};

#endif