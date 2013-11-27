#include <iostream>
#include <string>
using namespace std;
class Factura
{
public:
	Factura(){
		clave_pieza="";
		nombre="";
		articulos=0;
		precio=0;
	}
	void setClave(string clave){
		clave_pieza=clave;
	} 
	string getClave(){
		return clave_pieza;
	}
	void setNombre(string nombre){
		nombre=nombre;
	}
	string getNombre(){
		return nombre;
	}
	void setArticulo(int art){
		articulos=art;
	}
	int getArticulo(){
		return articulos;
	}
	void setPrecio(float p){
		precio=p;
	}
	float getPrecio(){
		return precio;
	}

	void obtenerMontoFactura(){
		
		
		cout << "El monto de la factura fue:\n"<< getArticulo()*getPrecio()<<endl;
	}

	/* data */
private:
	string clave_pieza;
	string nombre;
	int articulos; 
	float precio;
};
