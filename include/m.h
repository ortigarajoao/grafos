#ifndef MINHA_H
#define MINHA_H

#include <string>
#include <iostream>

class Minha{

private:
  std::string _texto = "Teste classe";

public:
  std::string texto(){return _texto;}

};

#endif // MINHA_H
