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
			case 1:  // guardar datos
				cout<<"Guardando datos en vector";
				ofstream archSalida ("sanchez.dat",ios::binary||ios::out);
				int nc;
				int cal;
				char nombre[20];
				int otro='s';
				while (otro=='s' || otro=='S'){
					cout<<"Dame numero de cuenta nombre y calificacion";
					cin>>nc;
					cin.getline(nombre,20,'\n');
					cin>>cal;
					archSalida.write((char *)&nc,sizeof(int));
					archSalida.write(nombre,20);
					archSalida.write((char *)&cal,sizeof(int));
					cout<<"Otro dato (s/n)";
					cin>>otro;
				}

				archSalida.close();
				break;
			case 2:  //mostrar datos
				break;
			case 3:  //guardar vector
				break;
			case 4:  //mostrar vector
				break;
			case 5:  //primero y ultimo
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
