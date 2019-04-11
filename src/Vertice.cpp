#include "Vertice.h"

Vertice::Vertice(int indice, std::string rotulo){
  _indice = indice;
  _rotulo = rotulo;
}

int Vertice::indice(){
  return _indice;
}

std::string Vertice::rotulo(){
  return _rotulo;
}

std::unordered_set<Vertice> Vertice::adjacentes(){
  std::unordered_set<Vertice> r;
  for( auto it = _adjacentes.begin(); it != _adjacentes.end(); ++it){
    r.insert(it->first);
  }
  return r;
}

bool Vertice::adicionaAresta(Vertice v, double peso){
  return (_adjacentes.insert({v,peso})) ? true : false;
}
