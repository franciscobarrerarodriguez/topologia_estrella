////////////////////////////////////////////////
// Clase: cliente.h
/////////////////////////////////////////////////

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <stdlib.h>
#include <pthread.h>
#include <sstream>
#include <vector>

#include <fstream>//Para leer archivos

#include "archivos.h"

using namespace std;

class Cliente {

	private:
		//****** Atributos ********
		int descriptorCliente;
		struct sockaddr_in servidorInfo;
		int puertoServidor;
		string ipServidor;
		bool estado;

		Archivos *archivos;

	public:
		//******* Constructores ******
		Cliente(void);
		Cliente(int, string);

		//******* destructor ****
		~Cliente();

		//******* Metodos ******
		void conectarServidor(void);
		static void * escucharServidor(void*);
		static void * escribirServidor(void*);

		//******* Getters ******
		int getDescriptor(void);
		bool getEstado(void);

		//******* Setters ******
		void setDescriptor(int);
		void setEstado(bool);

};//fin de la clase
