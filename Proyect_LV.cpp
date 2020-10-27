#include<iostream> 
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
void aniadir();
void escribir();
void lectura();
void modificar();
void memoria();
char res;
int contador;
int i;
string *palabra,*traduccion,*funcionalidad;
main(){
int menu;
do{palabra= new string[contador];
traduccion=new string[contador];
funcionalidad=new string[contador];
 cout<<"Buenas noches seleccione 1 opcion: "<<endl;
 cout<<"Palabras Guardadas #"<<contador<<endl;
	cout<<"1.escribir"<<endl<<"2.modificar"<<endl<<"3.Leer"<<endl;
	cin>>menu;
	switch (menu){
		case 1:contador++;
			aniadir();
			break;
			case 2:
				modificar();
				cout<<"Esta modificando"<<endl;
				 memoria();
				 cout<<"Desea ingresar otro dato s/n: ";
	cin>>res;
				break;
				case 3:
					 lectura();
					 break;

	} }while(res=='s');
	system("pause");
	return 0; }
void escribir(){
ofstream archivo;
archivo.open("proyecto1.txt",ios::out);
if (archivo.fail()){
	cout<<"No se puede abrir archivo";
	exit(1);
}		
archivo<<"Inicio del programa"<<endl;
archivo.close();
		cout<<"Desea ingresar otro dato s/n: ";
	cin>>res;	
}
void aniadir(){
ofstream archivo;

archivo.open("proyecto1.txt",ios::app);
if (archivo.fail()){
	cout<<"No se puede abrir archivo";
	exit(1);
}	
int i; i=contador-1;
palabra= new string[contador];
traduccion=new string[contador];
funcionalidad=new string[contador];
for( int a=0 ;a==0;a++){
cin.ignore();
cout<<"Ingrese una palabra en ingles"<<endl;
	getline(cin,palabra[i]);
	archivo<<contador<<palabra[i]<<endl;
cout<<"Ingrese traduccion al espanol"<<endl;
    getline(cin,traduccion[i]);
    archivo<<contador<<traduccion[i]<<endl;
cout<<"Ingrese funcionalidad"<<endl;
    getline(cin,funcionalidad[i]);
    archivo<<contador<<funcionalidad[i]<<endl;
} 
		cout<<"Desea ingresar otro dato s/n: ";
	cin>>res;
}

void lectura(){
	ifstream archivo;
	string alabra;
	archivo.open("proyecto1.txt",ios::in);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
while(!archivo.eof()){
	getline(archivo,alabra);
		cout<<alabra<<endl;
	}
		
	archivo.close();
		cout<<"Desea ingresar otro dato s/n: ";
	cin>>res;
}

void modificar(){	
cout<<"Ingrese el numero de palabra que desea modificar"<<endl;
cin>>i;
cout<<"La palabra que desea modificar es: "<<palabra[i]<<endl;
for( i;i<contador;i++){
cin.ignore();
cout<<"Ingrese una palabra en ingles"<<endl;
	getline(cin,palabra[i]);
cout<<"Ingrese traduccion al espanol"<<endl;
    getline(cin,traduccion[i]);
cout<<"Ingrese funcionalidad"<<endl;
    getline(cin,funcionalidad[i]);
}
	cout<<"Desea ingresar otro dato s/n: ";
	cin>>res;

}
void memoria(){
	ofstream archivo;
archivo.open("proyecto1.txt",ios::out);
if (archivo.fail()){
	cout<<"No se puede abrir archivo";
	exit(1);
}		
archivo<<"Inicio del programa"<<endl;
contador++;
int i=1;
for( i;i<contador;i++){
	archivo<<contador<<palabra[i]<<endl;
    archivo<<contador<<traduccion[i]<<endl;
    archivo<<contador<<funcionalidad[i]<<endl;

}
archivo.close();	
}
