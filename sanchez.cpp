#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int menu();
int main()
{

	int op;
	int calif[100];
	int nc;
	int cal;
	int i;
	int cuantos;
	char nombre[20];
	char otro='s';
	ofstream archSalida;
	ifstream arch;
	do{
		op=menu();
		switch(op){
			case 1:  // guardar datos
				cout<<"Guardando datos en vector\n";
				archSalida.open("sanchez.dat",ios::binary|ios::out);

				while (otro=='s' || otro=='S'){
					cout<<"Dame numero de cuenta";
					cin>>nc;
					cout<<"Dame nombre";
					cin>>nombre;
					cout<<"Dame calificacion";
					cin>>cal;
					archSalida.write((char *)&nc,sizeof(int));
					archSalida.write(nombre,20);
					archSalida.write((char *)&cal,sizeof(int));
					//cin.get();
					cout<<"Otro dato (s/n)";
					cin>>otro;
				}
				archSalida.close();
				break;
			case 2:  //mostrar datos
				cout<<"\nmostrando\n";
				arch.open("sanchez.dat",ios::binary|ios::in);
				i=0;	
				do{
					i++;
					arch.read((char *)&nc,sizeof(int));	
					arch.read(nombre,20);
					arch.read((char *)&cal,sizeof(int));
					cout<<" registro "<<i<<" "<<nc<<" - "<<nombre<<" - " <<cal<<"\n";
				}while (!arch.eof());
				arch.close();
				break;
			case 3:  //guardar vector
				cout<<"\nGuardando\n";
				cuantos=0;
				arch.open("sanchez.dat",ios::binary|ios::in);
				i=0;	
				do{
					
					arch.read((char *)&nc,sizeof(int));	
					arch.read(nombre,20);
					arch.read((char *)&cal,sizeof(int));
					calif[i]=cal;
					i++;
				}while (!arch.eof());
				cuantos=i-1;
				cout<<"Se leyeron " <<cuantos<<"\n";
				arch.close();
				break;
			case 4:  //mostrar vector
				cout<<"\n Datos del vector \n";
				for (i=0;i<cuantos;i++){
					cout<<"\nRegistro "<<i+1<<" "<<calif[i];
				}
				cout<<"\n\nFIN vector";
				break;
			case 5:  //primero y ultimo
				cout<<"\n    primer dato "<<calif[0];
				cout<<"\n    ultimo dato "<<calif[cuantos-1];
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
