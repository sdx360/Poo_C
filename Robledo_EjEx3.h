/*
Dan Williams Robledo Cruz
Se almacena el interes de los ahorradores y se calcula su saldo de ahorros
sacando su interes mediante la siguiente formula
saldo*tasaInteresAnual/12
a este se le suma el saldo actual y asi obtener el saldo de ahorro
*/

#include <iostream>
#include <string>
using namespace std;
class Robledo_EjEx3
{
public:
	Robledo_EjEx3(float v=0){
		saldoAhorros=v;
	}
	static void modificarTasaInteres(float a){
		tasaInteresAnual=a;
	}
	
	float CalcularInteresMensual() {
	
   		return saldoAhorros=((saldoAhorros*(tasaInteresAnual/100))/12)+saldoAhorros;
	}
private:
	float saldoAhorros;
	static float tasaInteresAnual;
};



	
