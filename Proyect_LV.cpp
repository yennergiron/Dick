#include <iostream>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include <windows.h>
using namespace std;
int cotador=0;
int menu(){
	system("cls");
	int x;
	cout<<"***Ingrese los siguientes registros***"<<endl;
	cout<<"**Elija una de las sigueintes opciones**"<<endl;
	cout<<"1. Agregar"<<endl;
	cout<<"2. Leer"<<endl;
	cout<<"3. Buscar"<<endl;
	cout<<"4. Modificar"<<endl;
	cout<<"5. Eliminar"<<endl;
	cout<<"6. Salir"<<endl;
	cin>>x;
	return x;
}
void agregar(ofstream&es){ int contador;
	system("cls");
	string palabra;
	string traduccion;
	string funcion;
    contador++; 
	es.open("proyecto.txt", ios::out | ios::app ); 
    cin.ignore(); 	
	cout<<"Palabra ";
	getline(cin,palabra);
	cout<<"Traduccion ";
	getline(cin,traduccion);
	cout<<"funcion ";
	getline(cin,funcion);
	es<<palabra<<endl<<traduccion<<endl<<funcion<<endl;
	es.close();
}
void verRegistros(ifstream&Lec){
	system("cls");
	string palabra;
	string traduccion;
	string funcion;
	Lec.open("proyecto.txt", ios::in);
	if (Lec.is_open()){
	cin.ignore();
	getline(Lec,palabra);
	while(!Lec.eof()){
		getline(Lec,traduccion);
		getline(Lec,funcion);
		cout<<"Palabra........ "<<palabra<<endl;
		cout<<"Traduccion:.... "<<traduccion<<endl;
		cout<<"Funcion:....... "<<funcion<<endl;
		cout<<"      "<<endl;
		getline(Lec,palabra);
	}
	Lec.close();
}else 
cout<<"Error el archivo no existe"<<endl;
	system("pause");
	
}

void buscarPersona(ifstream &Lec){
	system("cls");
	Lec.open("proyecto.txt", ios::in);
	string palabra,traduccion,funcion,buscador;
	bool encontrado = false;
	cout<<"Escriba la Palabra: ";
	cin.ignore();
	getline(cin,buscador);
	
	getline(Lec,palabra);
	while(!Lec.eof() && !encontrado){
	
		getline(Lec,traduccion);
		getline(Lec,funcion);
		if(palabra==buscador){
		cout<<"Palabra........ "<<palabra<<endl;
		cout<<"Traduccion:.... "<<traduccion<<endl;
		cout<<"Funcion:....... "<<funcion<<endl;
		cout<<"      "<<endl;
			encontrado = true;
		}
		
		getline(Lec,palabra);
	}
	Lec.close();
	
	if (!encontrado)
	cout<<"Palabra no encontrada"<<endl;
	system("pause");
}

void modificar(ifstream &Lec){
	system("cls");
	string palabra;
	string traduccion;
	string funcion;
	string buscador;
	string mpalabra;
	string mtraduccion;
	string mfuncion;
	Lec.open("proyecto.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Palabra ";
		cin.ignore();
		getline(cin,buscador);
		getline(Lec,palabra);
		while(!Lec.eof()){
		getline(Lec,traduccion);
		getline(Lec,funcion);
		if(palabra==buscador){
		cout<<"Palabra........ "<<palabra<<endl;
		cout<<"Traduccion:.... "<<traduccion<<endl;
		cout<<"Funcion:....... "<<funcion<<endl;
		cout<<"      "<<endl;
			cout<<"Nombre Nuevo ";

			getline(cin,mpalabra);
			cout<<"Traduccion Nuevo ";
			getline(cin,mtraduccion);
			cout<<"Funcion Nuevo ";
			getline(cin,mfuncion);
			aux<<mpalabra<<endl<<mtraduccion<<endl<<mfuncion<<endl;
		}else{
			aux<<palabra<<endl<<traduccion<<endl<<funcion<<endl;
		}
		getline(Lec,palabra);
		}
		Lec.close();
	    aux.close();
	}else
	cout<<"Error"<<endl;
	remove("proyecto.txt");
	rename("auxiliar.txt", "proyecto.txt");
	
}

void eliminar(ifstream &Lec){
	system("cls");
	string palabra;
	string traduccion;
	string funcion;
	string buscador;
	string mpalabra;
	string mtraduccion;
	string mfuncion;
	Lec.open("proyecto.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Palabra ";
		cin.ignore();
		getline(cin,buscador);
		getline(Lec,palabra);
		while(!Lec.eof()){
		getline(Lec,traduccion);
		getline(Lec,funcion);
		if(palabra==buscador){
			cout<<"Palabra Eliminada correctamente";
			Sleep(1500);
		}else{
			aux<<palabra<<endl<<traduccion<<endl<<funcion<<endl;
		}
		getline(Lec,palabra);
		}
		Lec.close();
	    aux.close();
	}else
	cout<<"Error"<<endl;
	remove("proyecto.txt");
	rename("auxiliar.txt", "proyecto.txt");
	
	
	
}



int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar(Esc);
				break;	
			case 2:
			verRegistros(Lec);	
				break;
			case 3:
			buscarPersona(Lec);
			    break;
			case 4:
			    modificar(Lec);
				break;
			case 5:
				eliminar(Lec);
				break;
					}
		
	}while(op != 6);
	return 0;
}
