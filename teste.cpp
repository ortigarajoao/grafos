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

    std::getline (_arquivo, strVertices);
    std::cout << strVertices << '\n';


  }else {
    std::cout << "Erro ao abir arquivo" << std::endl;
  }
  return 0;
}
