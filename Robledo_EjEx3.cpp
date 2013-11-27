/*
Dan Williams Robledo Cruz
Se almacena el interes de los ahorradores y se calcula su saldo de ahorros
sacando su interes mediante la siguiente formula
saldo*tasaInteresAnual/12
a este se le suma el saldo actual y asi obtener el saldo de ahorro
*/

#include <iostream>
#include <string>
#include "Robledo_EjEx3.h"
using namespace std;
float Robledo_EjEx3::tasaInteresAnual=3;

int main(int argc, char const *argv[])
{
	Robledo_EjEx3 ahorrador1(2000);
	cout<<"el saldo de ahorrro del cliente 1 es: "<<ahorrador1.CalcularInteresMensual()<<" cuando el Robledo_EjEx3 es 3%"<<endl;
	
	Robledo_EjEx3 ahorrador2(3000);	
	cout<<"el saldo de ahorrro del cliente 2 es: "<<ahorrador2.CalcularInteresMensual()<<" cuando el Robledo_EjEx3 es 3%"<<endl;

	Robledo_EjEx3::modificarTasaInteres(4);
	cout<<"el saldo de ahorrro del cliente 1 es: "<<ahorrador1.CalcularInteresMensual()<<" cuando el Robledo_EjEx3 es 4%"<<endl;
	
	cout<<"el saldo de ahorrro del cliente 2 es: "<<ahorrador2.CalcularInteresMensual()<<" cuando el Robledo_EjEx3 es 4%"<<endl;
	return 0;
}