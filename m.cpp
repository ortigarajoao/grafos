#include <iostream>

#include "include/Grafo.h"

int main(int argc, char const *argv[]) {
  Grafo g(argv[1]);


  g.buscaLargura(1);
  g.bellmanFord(1);
  g.floydWarshall();

  return 0;
}
