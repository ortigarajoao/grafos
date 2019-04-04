

class Vertice{

private:
  std::string _rotulo;
  std::vector<Vertice> _antecessores; //maybe map
  std::vector<Vertice> _sucessores;  //maybe map

public:
  std::string rotulo();
  std::vector<Vertice> antecessores();
  std::vector<Vertice> sucessores();
};
