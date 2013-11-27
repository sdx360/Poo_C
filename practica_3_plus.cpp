#include <iostream>
#include <string>
using namespace std;
#include "Factura.h"
int main(int argc, char const *argv[])
{
	string clave,nombre;
	int cantidad;
	float precio;
	Factura factura1;

	cout<< "Introduce la clave de la pieza"<<endl;
	getline(cin,clave);
	factura1.setClave(clave);

	cout<< "Introduce el nombre del producto"<<endl;
	getline(cin,nombre);
	factura1.setNombre(nombre);

	cout<<"Introduce la cantidad de articulos"<<endl;
	cin>>cantidad;
	factura1.setArticulo(cantidad);

	cout<<"Introduce el precio del articulo"<<endl;
	cin>>precio;
	factura1.setPrecio(precio);

	cout<<endl;
	factura1.obtenerMontoFactura();
}