#include <fstream>
#include <iostream>

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
            pos = strAux.find_first_of(" ");
            int vertice1 = std::stoi(strAux.substr(0,pos));
            int pos2 = strAux.find_first_of(" ",pos+1);
            int vertice2 = std::stoi(strAux.substr(pos+1,pos2-pos-1));
            double peso = std::stod(strAux.substr(pos2+1));
            (*_vertices)[vertice1]->adicionaAresta((*_vertices)[vertice2], peso);
            (*_vertices)[vertice2]->adicionaAresta((*_vertices)[vertice1], peso);
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

void Grafo::imprimir(){
  std::cout << "Aqui: " << (*_vertices)[1]->rotulo() << '\n';
  for(std::vector<Vertice*>::iterator it = _vertices->begin(); it != _vertices->end(); ++it ){
    std::cout << "Vertice: " << (*it)->indice() << ", Rotulo: " << (*it)->rotulo() << '\n';
  }
}
