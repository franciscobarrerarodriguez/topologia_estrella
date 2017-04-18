#include "archivos.h"

Archivos::Archivos (string ruta) {
  this->ruta = ruta;

  ifstream infile;
  infile.open("prueba.txt");

  if (infile.fail()) {
    cout << "No se pudo abrir el archivo" << endl;
    exit(1);
  }

  string item;
  int count = 0;

  while (!infile.eof()) {
    infile >> item;
    std::cout << item << '\n';
    count++;
  }
  cout << count << '\n';

}

void Archivos::setRuta(string ruta){
  this->ruta = ruta;
};

string Archivos::getRuta(){
  return this->ruta;
};
