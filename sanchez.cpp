#include<iostream>
#include<fstream>

using namespace std;
int menu();
int main()
{

	int op;
	int calif[100];
	
	do{
		op=menu();
		switch(op){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
		}

	}while (op!=0);

	return 0;
}

int menu()
{
	int opcion;
	cout<<"\nMENU PRINCIPAL\n";
	cout<<"1.- Agregar Datos\n";
	cout<<"2.- Mostrar Datos\n";
	cout<<"3.- Guardar Calificaciones - vector\n";
	cout<<"4.- Mostrar Vector\n";
	cout<<"5.- Mostrar Primero y Ultimo\n";
	cout<<"0.- SALIR\n";
	do{
		cout<<"\nIngresa tu opcion ";
		cin>>opcion;
	}while (opcion<0 || opcion>5);
	return opcion;
}
