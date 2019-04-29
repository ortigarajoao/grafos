#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <algorithm>

#include "../include/Grafo.h"

Grafo::Grafo(std::string arquivo){
  std::ifstream _arquivo(arquivo);

  if(_arquivo.is_open()){
    std::string strAux;
    int pos;
    std::getline (_arquivo, strAux);
    if(strAux.compare(0,9, "*vertices") == 0){
      int nVertices = std::stoi(strAux.substr(10));
      if(nVertices){
        _vertices = new std::vector<Vertice*>(nVertices);
        for(int i = 1; i <= nVertices; i++){
          std::getline(_arquivo, strAux);
          pos = strAux.find_first_of(" ");
          if(pos != std::string::npos){
            (*_vertices)[i] = new Vertice(i,strAux.substr(pos+1));
          } else {
            std::cout << "Erro na formatacao da linha: " << i << std::endl;
          }
        }
        std::getline(_arquivo, strAux);
        if(strAux.compare("*edges") == 0){
          std::getline(_arquivo, strAux);
          while(_arquivo.good()){
            _qtdArestas++;
            pos = strAux.find_first_of(" ");
            int vertice1 = std::stoi(strAux.substr(0,pos));
            int pos2 = strAux.find_first_of(" ",pos+1);
            int vertice2 = std::stoi(strAux.substr(pos+1,pos2-pos-1));
            double peso = std::stod(strAux.substr(pos2+1));
            (*_vertices)[vertice1]->adicionaAresta((*_vertices)[vertice2], peso);
            (*_vertices)[vertice2]->adicionaAresta((*_vertices)[vertice1], peso);
            std::pair<Vertice*,Vertice*>* par1 = new std::pair<Vertice*,Vertice*>((*_vertices)[vertice1],(*_vertices)[vertice2]);
            std::pair<Vertice*,Vertice*>* par2 = new std::pair<Vertice*,Vertice*>((*_vertices)[vertice2],(*_vertices)[vertice1]);
            _arestas.insert(par1);
            _arestas.insert(par2);
            std::getline(_arquivo, strAux);
          }
        } else {
          std::cout << "Erro de formatacao de *edges" << std::endl;
        }
      } else {
          std::cout << "Erro de transformacao de valor numerico da linha: 1" << std::endl;
      }
    } else {
      std::cout << "Erro na formatacao da linha: 1" << std::endl;
    }
  } else {
    std::cout << "Erro ao abir arquivo" << std::endl;
  }
}

Grafo::~Grafo(){
  delete _vertices;
}

int Grafo::qtdVertices(){
  return _vertices->size();
}

int Grafo::qtdArestas(){
  return _qtdArestas;
}

int Grafo::grau(int vertice){
  return (*_vertices)[vertice]->grau();
}

std::string Grafo::rotulo(int vertice){
  return (*_vertices)[vertice]->rotulo();
}

std::unordered_set<Vertice*>* Grafo::adjacentes(int vertice){
  return (*_vertices)[vertice]->adjacentes();
}

bool Grafo::haAresta(int vertice1, int vertice2){
  return (*_vertices)[vertice1]->haAresta((*_vertices)[vertice2]);
}

double Grafo::peso(int vertice1, int vertice2){
  if(this->haAresta(vertice1,vertice2)){
    return (*_vertices)[vertice1]->peso((*_vertices)[vertice2]);
  } else {
    return std::numeric_limits<double>::max();
  }
}

void Grafo::imprimirVertices(){
  for (int i = 1; i <= (*_vertices).size(); i++){
    std::cout << "Vertice: " << (*_vertices)[i]->indice() << ", Rotulo: " << (*_vertices)[i]->rotulo() << '\n';
  }
}

void Grafo::imprimirArestas(int vertice){
  std::unordered_set<Vertice*>* adj = (*_vertices)[vertice]->adjacentes();
  for (auto it = adj->begin(); it != adj->end(); ++it){
    std::cout << (*it)->indice() << ", ";
  }
  std::cout << '\n';
}

Vertice* Grafo::vertice(int v){
  return (*_vertices)[v];
}

void Grafo::buscaLargura(int v){
  std::vector<bool> visitados(this->qtdVertices()+1);
  std::vector<int> distancias(this->qtdVertices()+1, std::numeric_limits<int>::max());
  std::queue<Vertice*> fila;
  fila.push((*_vertices)[v]);
  distancias[v] = 0;
  visitados[v] = true;
  int niveis = 0;
  while(!fila.empty()){
    Vertice* atual = fila.front();
    fila.pop();
    std::unordered_set<Vertice*>* adj = atual->adjacentes();
    for (auto it = adj->begin(); it != adj->end(); ++it){
      if(!visitados[(*it)->indice()]) {
        visitados[(*it)->indice()] = true;
        distancias[(*it)->indice()] = distancias[atual->indice()] + 1;
        niveis = distancias[(*it)->indice()] >= niveis ? distancias[(*it)->indice()] : niveis;
        fila.push((*it));
      }
    }
  }
  std::vector<std::string> imprimir(niveis+1);
  imprimir[0] = "0: " + std::to_string(v);
  std::cout << imprimir[0] << '\n';
  for(int i= 1; i <= niveis; i++){
    imprimir[i] = std::to_string(i)+": ";
    for(int j = 1; j <= this->qtdVertices(); j++){
      if(distancias[j] == i){
        imprimir[i] += std::to_string((*_vertices)[j]->indice()) + ",";
      }
    }

    imprimir[i].erase(imprimir[i].cend()-1);
    std::cout << imprimir[i] << '\n';
  }
}

bool Grafo::hierholzer(){
  //std::unordered_map<std::pair<Vertice*,Vertice*>,bool> visitados;
  //std::vector<Vertice*> ciclo;
  //for(auto it = _arestas.begin(); it != _arestas.end(); ++it){
    //visitados.insert(std::make_pair<std::pair<Vertice*,Vertice*>,bool>((*it),false);
  //}
  //Vertice* v = (*_vertices)[1];
  return false;


}

void Grafo::floydWarshall(){
  double distancia[this->qtdVertices()+1][this->qtdVertices()+1];
  for(auto it = _arestas.begin(); it != _arestas.end(); ++it){
    distancia[(*it)->first->indice()][(*it)->second->indice()] = (*it)->first->peso((*it)->second);
  }
  for(int i = 1; i <= this->qtdVertices(); i++){
    distancia[i][i] = 0;
  }
  for(int k = 1; k <= this->qtdVertices(); k++){
    for(int i = 1; i <= this->qtdVertices(); i++){
      for(int j = 1; j <= this->qtdVertices(); j++){
        if(distancia[i][j] > distancia[i][k] + distancia[k][j]){
          distancia[i][j] = distancia[i][k] + distancia[k][j];
        }
      }
    }
  }
  for(int i = 1; i <= this->qtdVertices(); i++){
    std::string imprimir = std::to_string(i) + ":";
    for(int j = 1; j <= this->qtdVertices(); j++){
      imprimir += std::to_string(distancia[i][j]) + ",";
    }
    imprimir.erase(imprimir.cend()-1);
    std::cout << imprimir << '\n';
  }
}

bool Grafo::bellmanFord(int v){
  std::vector<double> distancias(this->qtdVertices()+1, std::numeric_limits<double>::max());
  std::vector<int> antecessores(this->qtdVertices()+1, -1);
  distancias[v] = 0;  
  for(int i = 1; i <= this->qtdVertices()-1; i++){
    for(auto it = _arestas.begin(); it != _arestas.end(); ++it){
      if(distancias[(*it)->second->indice()] > distancias[(*it)->first->indice()] + (*it)->first->peso((*it)->second)){
        distancias[(*it)->second->indice()] = distancias[(*it)->first->indice()] + (*it)->first->peso((*it)->second);
        antecessores[(*it)->second->indice()] = (*it)->first->indice();
      }
    }
  }
  for(auto it = _arestas.begin(); it != _arestas.end(); ++it){
    if(distancias[(*it)->second->indice()] > distancias[(*it)->first->indice()] + (*it)->first->peso((*it)->second)){
      return false;
    }
  }

  for(int i = 1; i <= this->qtdVertices(); i++){
    std::string imprimir = "=d ;" + std::to_string(i);
    int cont = i;
    while(antecessores[cont] != -1){
      imprimir += "," + std::to_string(antecessores[cont]);
      cont = antecessores[cont];
    }
    imprimir += " :" + std::to_string(i);
    std::reverse(imprimir.begin(), imprimir.end());
    imprimir += std::to_string(distancias[i]);
    std::cout << imprimir << '\n';
  }
  return true;
}
