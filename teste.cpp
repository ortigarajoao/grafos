#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char const *argv[]) {

  std::ifstream _arquivo(argv[1]);
  if(_arquivo.is_open()){
    std::string strVertices;
    std::getline (_arquivo, strVertices);
    int n = std::stoi(strVertices.substr(10));
    for(int i = 1; i <= n; i++){
      std::getline (_arquivo, strVertices);
      std::cout << strVertices << '\n';
    }
    std::string strAux;
    std::getline (_arquivo, strAux);
    if(strAux.compare("*edges") == 0){
      std::cout << "Achou edges" << '\n';
      int count = 0;
      std::getline(_arquivo, strAux);
      while(_arquivo.good()){
        std::cout << "Counter:" << count << '\n';
        count++;
        std::cout << "Linha: " << strAux << '\n';
        std::cout << "Good: " <<_arquivo.good() << "\n";
        int pos = strAux.find_first_of(" ");
        int vertice1 = std::stoi(strAux.substr(0,pos));
        int pos2 = strAux.find_first_of(" ",pos+1);
        int vertice2 = std::stoi(strAux.substr(pos+1,pos2-pos-1));
        double peso = std::stod(strAux.substr(pos2+1));
        std::cout << vertice1 << "-" << vertice2 << "-" << peso << std::endl;
        std::getline(_arquivo, strAux);
      }
    } else {
      std::cout << "Erro de formatacao de *edges" << std::endl;
    }
    


  }else {
    std::cout << "Erro ao abir arquivo" << std::endl;
  }
  return 0;
}
