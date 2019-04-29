#ifndef GRAFO_H
#define GRAFO_H

#include "../include/Vertice.h"

#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <utility>

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
  std::unordered_set<Vertice*>* adjacentes(int vertice);
  bool haAresta(int vertice1, int vertice2);
  double peso(int vertice1, int vertice2);
  void imprimirVertices();
  void imprimirArestas(int vertice);
  Vertice* vertice(int v);

  void buscaLargura(int v);
  bool bellmanFord(int v);
  void floydWarshall();
  bool hierholzer();
  bool buscaSubcicloEuleriano(int v, std::unordered_map<std::pair<Vertice*,Vertice*>*,bool>* visitados, std::vector<Vertice*>* ciclo);

private:
  std::vector<Vertice*>* _vertices;
  std::unordered_set<std::pair<Vertice*,Vertice*>*> _arestas;
  int _qtdArestas = 0; //Para diminuir procuras

};

#endif //GRAFO_H
