#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Archivos {

private:

  string ruta;

public:
  //****** Constructores ******
  Archivos(string);//Recibe la ruta del archivo.
  //****** Destructor ******
  ~Archivos();

  void setRuta(string ruta);
  string getRuta();
};
