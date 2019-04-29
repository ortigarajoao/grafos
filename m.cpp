#include <iostream>

#include "include/Grafo.h"

int main(int argc, char const *argv[]) {
  Grafo g(argv[1]);

  std::cout << "Busca em largura" << '\n';
  g.buscaLargura(1);
  std::cout << "------------------------" << '\n';
  std::cout << "Bellman-Ford" << '\n';
  g.bellmanFord(1);
  std::cout << "------------------------" << '\n';
  std::cout << "Floyd-Warshall" << '\n';
  g.floydWarshall();

  return 0;
}
