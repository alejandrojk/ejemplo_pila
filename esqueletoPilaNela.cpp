/*// Hacer 2 estructuras una llamada Notas que tendrá los siguientes campos: nota1, nota2, nota3;
// y otro llamada Alumno que tendrá los siguientes miembros: nombre, sexo, fecha nacimiento.
// Hacer que la estructura Notas este anidada en la estructura Alumno.
// Realizar un programa, que mientras el usuario lo desee, ingrese los datos de hasta 10 alumnos.
// Luego muestre los datos de todos los alumnos y su promedio; e  informe  aquel alumno que tenga el mejor promedio.*/


#include<iostream>
using namespace std;


struct Notas{
	float nota1;
	float nota2;
	float nota3;
};

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Alumno{
	char nombre[15];
	char sexo[10];
	Fecha fn;
	Notas notas;
};

float promedio(Alumno a){
	return ((a.notas.nota1+a.notas.nota2+a.notas.nota3)/3);
}

void mostrarAlumno(Alumno a){
	cout<<"\n\t\tNombre: "<<a.nombre;
	cout<<"\n\t\tSexo: "<<a.sexo;
	cout<<"\n\t\tFecha de nacimiento: \n\t\tDia: "<<a.fn.dia;
	cout<<"\n\t\tMes: "<<a.fn.mes;
	cout<<"\n\t\tAnio: "<<a.fn.anio;
	cout<<"\n\t\tPromedio: "<<promedio(a);
	cout<<"\n";
}

void mostrarMejor(Alumno a[], int cant){
	if(cant!=0){
		float mejor=0;
		int posicion;
		int i;
		for( i=0; i<cant; i++){
			float prom=promedio(a[i]);
			if(prom>mejor){
				mejor=promedio(a[i]);
				posicion=i;
			}
		}
		mostrarAlumno(a[posicion]);
	}else{
		cout<<"\n\t\tNo hay alumnos ingresados";
	}
}

void mostrarTodos(Alumno a[], int cant){
	if(cant!=0){
		int i;
		for(i=0;i<cant;i++){
			mostrarAlumno(a[i]);
		}
	}else{
		cout<<"\n\t\tNo hay alumnos ingresados";
	}
}

Alumno cargarAlumno(){
	Alumno a;
	cout<<"\n\t\tIngrese el nombre: ";
	cin>>a.nombre;
	cout<<"\n\t\tIngrese el sexo: ";
	cin>>a.sexo;
	cout<<"\n\t\tIngrese la fecha de nacimiento:"<<endl;
	cout<<"\n\t\t\tDia: ";
	cin>>a.fn.dia;
	cout<<"\n\t\t\tMes: ";
	cin>>a.fn.mes;
	cout<<"\n\t\t\tAnio: ";
	cin>>a.fn.anio;
	cout<<"\n\t\tIngrese 3 notas:"<<endl;
	cout<<"\n\t\t\tPrimer nota: ";
	cin>>a.notas.nota1;
	cout<<"\n\t\t\tSegunda nota: ";
	cin>>a.notas.nota2;
	cout<<"\n\t\t\tTercer nota: ";
	cin>>a.notas.nota3;
	return a;
}

int main(){
	int opcion, cant=0;
	Alumno a[10];
	do{
		cout<<"\n\t\tMENU DE OPCIONES: "<<endl;
		cout<<"\t(1)\tCargar datos de alumno"<<endl;
		cout<<"\t(2)\tMostrar todos los alumnos"<<endl;
		cout<<"\t(3)\tMostrar al alumno con mejor promedio"<<endl;
		cout<<"\t(4)\tSalir"<<endl;
		cout<<"\tIngrese el numero de la opcion: ";
		cin>>opcion;

		switch(opcion){
			case 1: {
				a[cant]=cargarAlumno();
				cant++;
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				mostrarTodos(a,cant);
				system("pause");
				system("cls");
				break;
			}
			case 3 :{
				mostrarMejor(a,cant);
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				cout<<"\n\n\tPresione enter para salir\n\t";
				system("pause");
				system("cls");
				break;
			}
			default:{
				cout<<"\n\tERROR. Numero de opcion ingresada incorrecto. Por favor ingrese un numero de opcion valido (1, 2, 3 o 4). ";
				cin>>opcion;
				system("pause");
				system("cls");
			}
		}
	}while(opcion!=4);
}
