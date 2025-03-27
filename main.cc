#include "Parser.h"
#include "Nif.h"
#include "Persona.h"
#include "Alumno.h"

// Para poder realizar la practica primero edite la clase nif para que recogiera la letra, decidi, guardar la letra en asci al recibirla y asi evitar no leer dos claves iguales
// mas adelante pensaba realizar el mismo metodo con alumno, pero no pude, además debía editar la creación de la tabla de hash con templates para que recogiera tanto con Persona como NIF como alumno
// usando el template.
int main(int argc, char **argv) {
  Parser parser(argc, argv);
  if (!parser.IsValid()) {
    return EXIT_FAILURE;
  }
  std::cout << "escoja el tipo de clave a guardar" << std::endl;
  std::string type;
  std::cin >> type; 
  if (type == "Persona"){
  if (parser.GetHashType() == "open") {
    auto* table = HashTableBuilder::BuildOpenHashTable(parser);
    Menu::Run(table);
    delete table;
  } else if (parser.GetHashType() == "close") {
    auto* table = HashTableBuilder::BuildClosedHashTable(parser);
    Menu::Run(table);
    delete table;
  }
  } else if (type == "Alumno") {
  if (parser.GetHashType() == "open") {
    auto* table = HashTableBuilder::BuildOpenHashTable(parser);
    Menu::Run(table);
    delete table;
  } else if (parser.GetHashType() == "close") {
    auto* table = HashTableBuilder::BuildClosedHashTable(parser);
    Menu::Run(table);
    delete table;
  }
  } else if (type == "NIF") {
  if (parser.GetHashType() == "open") {
    auto* table = HashTableBuilder::BuildOpenHashTable(parser);
    Menu::Run(table);
    delete table;
  } else if (parser.GetHashType() == "close") {
    auto* table = HashTableBuilder::BuildClosedHashTable(parser);
    Menu::Run(table);
    delete table;
  }
  }

  return 0;
}
