#include "../include/Vertice.h"

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

std::unordered_set<Vertice*>* Vertice::adjacentes(){
  std::unordered_set<Vertice*>* r = new std::unordered_set<Vertice*>();
  for( auto it = _adjacentes.begin(); it != _adjacentes.end(); ++it){
    r->insert(it->first);
  }
  return r;
}

bool Vertice::adicionaAresta(Vertice* v, double peso){
  std::pair<Vertice*,double> p = std::make_pair(v,peso);
  if(_adjacentes.insert(p).second) {
    return true;
  }
  return false;
}

double Vertice::peso(Vertice* v){
  if(_adjacentes.find(v) != _adjacentes.end()){
    return _adjacentes[v];
  }
  return -1.0;
}
