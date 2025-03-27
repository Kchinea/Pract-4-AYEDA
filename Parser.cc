#include "Parser.h"

Parser::Parser(int argc, char** argv) {
  ParseArgs(argc, argv);
}

void Parser::ParseArgs(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-ts") {
      if (i + 1 < argc) {
        table_size_ = std::stoi(argv[i + 1]);
        i++;
      } else {
        std::cerr << "Error: -ts requires an argument." << std::endl;
        valid_ = false;
        return;
      }
    } else if (arg == "-fd") {
      if (i + 1 < argc) {
        dispersion_func_ = argv[i + 1];
        i++;
      } else {
        std::cerr << "Error: -fd requires an argument." << std::endl;
        valid_ = false;
        return;
      }
    } else if (arg == "-hash") {
      if (i + 1 < argc) {
        hash_type_ = argv[i + 1];
        i++;
      } else {
        std::cerr << "Error: -hash requires an argument." << std::endl;
        valid_ = false;
        return;
      }
    } else if (arg == "-bs") {
      if (i + 1 < argc) {
        block_size_ = std::stoi(argv[i + 1]); 
        i++;
      } else {
        std::cerr << "Error: -bs requires an argument." << std::endl;
        valid_ = false;
        return;
      }
    } else if (arg == "-fe") {
      if (i + 1 < argc) {
        exploration_func_ = argv[i + 1];
        i++;
      } else {
        std::cerr << "Error: -fe requires an argument." << std::endl;
        valid_ = false;
        return;
      }
    } else {
      std::cerr << "Error, option not found " << arg << std::endl;
      valid_ = false;
      return;
    }
  }
  if(block_size_ == 0 && hash_type_ == "close") {
    std::cerr << "Error, option not found if tyoe is close need a block size " << std::endl;
    valid_ = false;
    return;
  }
}
