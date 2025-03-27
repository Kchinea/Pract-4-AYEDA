// #ifndef NIF_H_
// #define NIF_H_

// #include <iostream>
// constexpr int max_digits = 100000000;


// class NIF {
//   public:
//     NIF();
//     NIF(long);
    
//     long operator[](int) const;
//     friend std::istream& operator>>(std::istream& is, NIF& nif);

//     bool operator==(const NIF&) const;
//     bool operator!=(const NIF&) const;
//     bool operator<(const NIF&) const;
//     bool operator>(const NIF&) const;
    
//     long unsigned int size() const;
    
//     operator long() const;
  
//   private:
//     long nif_;
// };

// #endif

#ifndef NIF_H_
#define NIF_H_

#include <iostream>

class NIF {
  public:
    NIF();
    NIF(const std::string& nif_str); // Constructor para recibir el NIF como string
    
    long getNumber() const; // Método para obtener el número completo (con la letra)
    
    long operator[](int) const;
    bool operator==(const NIF&) const;
    bool operator!=(const NIF&) const;
    bool operator<(const NIF&) const;
    bool operator>(const NIF&) const;
    long unsigned int size() const;
    
    operator long() const;
    
    friend std::istream& operator>>(std::istream& is, NIF& nif);

  private:
    long nif_number_; // Almacena el número con la letra transformada
};

#endif