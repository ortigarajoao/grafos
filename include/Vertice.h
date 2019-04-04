#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include <unordered_map>

class Vertice{

private:
  std::string _rotulo;
  std::unordered_map<int,Vertice> _antecessores; //maybe map
  std::unordered_map<int,Vertice> _sucessores;  //maybe map

public:
  std::string rotulo();
  std::unordered_map<int,Vertice> antecessores();
  std::unordered_map<int,Vertice> sucessores();
};

#endif //VERTICE_H
