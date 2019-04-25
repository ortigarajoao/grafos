#include <iostream>

#include "include/Grafo.h"

int main(int argc, char const *argv[]) {
  std::cout << "Antes Grafo" << '\n';
  Grafo g(argv[1]);
  std::cout << "Depois Grafo" << '\n';
  g.imprimirVertices();
  for(int i = 1; i <= g.qtdVertices(); i++){
    std::cout << "Vertice:" << g.vertice(i)->indice() << ",Rotulo: " << g.vertice(i)->rotulo() << '\n';
    g.imprimirArestas(i);
  }
  return 0;
}
