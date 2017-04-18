#include <iostream>
#include "Servidor.h"
#include "Cliente.h"

using namespace std;

int main (int argc,char *argv[]){

	int tipo=0;
	int puerto=0;
	cout<<"selecciones el tipo : 1: Servidor, 2: Cliente: cual?:   ";
	cin >> tipo;
	cin.get();

	cout <<"puerto: ";
	cin >> puerto;
	cin.get();

	int val =tipo;

	if(val==1){

		Servidor servidor;

		servidor.setPuerto(puerto);
		servidor.inicializarServidor();
		servidor.ejecutarServidor();

		while(1);
	}
	if (val==2){
		cout<< "nombre del host o ip";
		           string host;
		           getline(cin,host);

		   Cliente *cliente= new Cliente(puerto,host);

		   cliente->conectarServidor();        
	}

	return 0;
}
