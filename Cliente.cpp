#include "Cliente.h"


Cliente::Cliente(){

	this->puertoServidor=9000;

	this->ipServidor="127.0.0.1";

	this->estado=true;
}

Cliente::Cliente(int puerto,string ip){

	this->puertoServidor=puerto;

	this->ipServidor=ip;

	this->estado=true;


}


void * Cliente::escucharServidor(void * cli){

  Cliente* cliente=(Cliente *) cli;

  char mensajeDeServidor[60];

  while(1){

	  recv(cliente->getDescriptor(),(void *)&mensajeDeServidor ,60,0);

	  cout<<mensajeDeServidor<<endl;

  }


}
void Cliente::menu(){
	bool bandera=false;
	char tecla;
	

	do{
		system("cls");
		cin.clear();

		cout <<"menu almacenamiento" <<endl;
		cout <<"--------****---------"<<endl << endl;
		cout <<"1 . subir archivo"<<endl;
		cout <<"2 . solicitar archivos por maquinas"<<endl;
		cout <<"3 . eliminar archivos"<<endl;
		cout <<"4 . balancear carga "<<endl;
		cout <<"5 . terminar conexion"<<endl;

		cin >>opcion;

		switch(opcion){
		
			case '1':
				system("cls");
				cout << "opcion 1: subir archivo.\n";
				enviarArchivo();
			break;

			case '2':
				system("cls");
				cout << "opcion 2: archivos por maquinas.\n";
			
			break;

			case '3':
				system("cls");
				cout << "opcion 3: eliminar archivos.\n";
			
			break;

			case '4':
				system("cls");
				cout << "opcion 4: balancear carga.\n";
			
			break;
		
			case '5':
				system("cls");
				cout << "opcion 5: terminar conexion.\n";
			
			break;
		}
		while(bandera!=true);
	return =0;
	}

}

void * Cliente::escribirServidor(void * cli){

	Cliente* cliente=(Cliente *) cli;


	int conectado=1;

	while (conectado){


		char msg[128];

		sprintf(msg,"hola");


		int i=send(cliente->getDescriptor(),(void *)msg,sizeof(msg),0);

		sleep(1);


		if(i==-1){

			conectado=0;

			cout<<"se desconecto del servidor"<<endl;

            close(cliente->getDescriptor());

          //  exit(EXIT_SUCCES);

            exit(EXIT_SUCCESS);

		}

	}

}







void Cliente::conectarServidor(){


       descriptorCliente =socket(AF_INET,SOCK_STREAM,0);

       servidorInfo.sin_family=AF_INET;

      // servidorInfo.sin_family=AF_INET;//OJO MAYUSCULA

       inet_pton(AF_INET,ipServidor.c_str(),&servidorInfo.sin_addr);

       servidorInfo.sin_port=htons(puertoServidor);


       int conn=connect(descriptorCliente,(struct sockaddr *)&servidorInfo,sizeof(servidorInfo));


       if(conn!=1){


       	  pthread_t hiloEscucha;

       	   pthread_create(&hiloEscucha,NULL,escucharServidor,(void *)this);


       	   pthread_t hiloEscribe;

       	   pthread_create(&hiloEscribe,NULL,escribirServidor,(void *)this);
		cont <<"conexion exitosa"<<endl;


       	   while(1);
	menu();


       }else{

       	 cout<<"no se pudo conectar con el servidor"<<endl;


       }

}


void * Cliente::enviarArchivo(){
	char buffer[BUFFSIZE];
	FILE *archivo;
	archivo=fopen("clieInfo.cpp","rb");
	if(!archivo){
		cout<< "no se pudo abrir archivo" << endl;

	}
	while(!feof(archivo)){
		fread(buffer,sizeof(char),BUFFSIZE,archivo);
			if(send(clien->getDescriptor(), buffer,BUFFSIZE,0)==ERROR)
				cout <<"error al enviar archivo" << endl;
	}
	fclose(archivo);
}

int Cliente::getDescriptor(){


	return this-> descriptorCliente;

}


void Cliente::setDescriptor(int descriptor){

	this->descriptorCliente=descriptor;


}


bool Cliente::getEstado(){


	return this->estado;

}

void Cliente::setEstado(bool estado){

	  this->estado=estado;

}
