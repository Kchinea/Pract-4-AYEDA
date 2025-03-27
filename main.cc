#include "Builder.h"
#include "Menu.h"

int main(int argc, char **argv) {
  Parser parser(argc, argv);
  if (!parser.IsValid()) {
    return EXIT_FAILURE;
  }

  if (parser.GetHashType() == "open") {
    auto* table = HashTableBuilder::BuildOpenHashTable(parser);
    Menu::Run(table);
    delete table;
  } else if (parser.GetHashType() == "close") {
    auto* table = HashTableBuilder::BuildClosedHashTable(parser);
    Menu::Run(table);
    delete table;
  }
  return 0;
}
