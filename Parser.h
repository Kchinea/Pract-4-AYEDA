#ifndef PARSER_H_

 

#define PARSER_H_
 


 

#include <iostream>
 

#include <string>
 


 

class Parser {
 

 public:
 

  Parser(int argc, char** argv);
 

  
 

  unsigned GetTableSize() const { return table_size_; }
 

  unsigned GetBlockSize() const { return block_size_; }
 

  std::string GetHashType() const { return hash_type_; }
 

  std::string GetDispersionFunc() const { return dispersion_func_; }
 

  std::string GetExplorationFunc() const { return exploration_func_; }
 

  bool IsValid() const { return valid_; }
 


 

 private:
 

  unsigned table_size_ = 0;
 

  unsigned block_size_ = 0;
 

  std::string hash_type_;
 

  std::string dispersion_func_;
 

  std::string exploration_func_;
 

  bool valid_ = true;  // Se pone en false si hay algún error
 


 

  void ParseArgs(int argc, char** argv);
 

};
 


 

#endif // PARSER_H_