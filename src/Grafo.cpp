#include <fstream>
#include <iostream>

#include "Grafo.h"

Grafo::Grafo(std::string arquivo){
  std::ifstream _arquivo(arquivo);

  if(_arquivo.is_open()){
    std::string strAux;
    int pos;
    std::getline (_arquivo, strAux);
    if(strVertices.compare(0,9, "*vertices") == 0){
      int nVertices = std::stoi(strAux.substr(10));
      if(nVertices){
        _vertices = std::vector<Vertice>(nVertices);
        for(int i = 1; i <= nVertices; i++){
          std::getline(_arquivo, strAux);
          pos = strAux.find_first_of(" ");
          if(pos != std::string::npos){
            _vertices[i] = Vertice(i,strAux.substr(pos+1));
          } else {
            std::cout << "Erro na formatacao da linha: " << i << std::endl;
          }
        }
        std::getline(_arquivo, strAux);
        if(strAux.compare("*edges") == 0){
          while(_arquivo.good()){
            std::getline(_arquivo, strAux);
            pos = strAux.find_first_of(" ");
            int vertice1 = std::stoi(strAux.substr(0,pos));
            int pos2 = strAux.find_first_of(" ",pos+1);
            int vertice2 = std::stoi(strAux.substr(pos+1,pos2-pos-1));
            double peso = std::stod(strAux.substr(pos2+1));
            _vertices[vertice1].adicionaAresta(_vertices[vertice2], peso);
            _vertices[vertice2].adicionaAresta(_vertices[vertice1], peso);

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
