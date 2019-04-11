#include <iostream>

#include "include/Grafo.h"

int main(int argc, char const *argv[]) {
  std::cout << "Antes Grafo" << '\n';
  Grafo g(argv[1]);
  std::cout << "Depois Grafo" << '\n';
  g.imprimir();
  return 0;
}
