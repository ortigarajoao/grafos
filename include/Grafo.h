#ifndef GRAFO_H
#define GRAFO_H

#include "../include/Vertice.h"

#include <vector>
#include <string>

class Grafo{

public:
  Grafo();
  ~Grafo();
  Grafo(std::string arquivo);
  bool ler(std::string arquivo);

  int qtdVertices();
  int qtdArestas();
  int grau(int vertice);
  std::string rotulo(int vertice);
  bool haAresta(int vertice1, int vertice2);
  void imprimir();

private:
  std::vector<Vertice*>* _vertices;

};

#endif //GRAFO_H
