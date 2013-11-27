/*
Dan Williams Robledo Cruz
Examen 3: LowPower 
Un programa para distribuir baterias a unos chips que produce la compañia GRAPE, los chips se
distribuyen mediante la ecuacion 2kn, donde k es el numero de maquina y n el numero de pilas
por chip, cada maquina cuenta con 2 chips, se calcula la minima diferencia de potencia posible
entre las baterias y de esas se saca el maximo de los minimos de diferencia de todas la maqunas
y se imprimi las combinaciones

*/

#include <iostream>
#include <string>
using namespace std;

void msgErr(){

	cout<<"Error cantida de elementos"<<endl;
}



class Machine
{
public:
	Machine() {}
	void getmemory(int total){
		powerbateries= (int *) malloc(total*sizeof(int));
	}
	void llenar(char *argv[], int tope);
	void imprimir();
	void ordenar(int total);
	void salida(int machine,int bateria);
	/* data */
private:
	int *powerbateries;
};

void Machine::llenar(char *argv[], int tope){
	for (int i = 0; i < tope; ++i)
	{
		powerbateries[i]=atoi(argv[i+3]);
		//cout<<argv[i+3]<<endl;
	}
}
void Machine::imprimir(){
	for (int i = 0; i < 12; ++i)
	{
		cout<<powerbateries[i]<<endl;
	}
}
void Machine::ordenar(int total){
	for (int i = 0; i < total; ++i)
	{
			for (int j = 0; j < total-1; ++j)
			{
				if(powerbateries[j]>powerbateries[j+1])
				{
					int temp =powerbateries[j];
					powerbateries[j] =powerbateries[j+1];
					powerbateries[j+1] = temp;

				}
			}
		
	}
}
void Machine::salida(int machine,int bateria){
	int aux[machine*2];
	int num1,num2,a=0,aux2;
	//int Salida[machine*bateria*2-1];
	int menor=powerbateries[1]-powerbateries[0];
	num1=1;
	num2=0;
	for (int h = 0; h < machine; ++h)
	{
		for (int i = 1; i < machine*bateria*2-1; ++i)
		{
			if(powerbateries[i]!=-1&&powerbateries[i+1]!=-1){
				if(powerbateries[i+1]-powerbateries[i]<menor)
				{
					num1=i+1;
					num2=i;
					menor=powerbateries[i+1]-powerbateries[i];
				}
			}
		}
		aux[a]=powerbateries[num1];
		//cout<<aux[a]<<endl;
		a++;
		aux[a]=powerbateries[num2];
		//cout<<aux[a]<<endl;
		a++;
		powerbateries[num1]=-1;
		powerbateries[num2]=-1;
		aux2=menor;
		menor=100000000;
	}
	int mayor=0;
	for (int i = 0; i < machine*2-1; ++i)
	{
		if(mayor<aux[i]-aux[i+1]){
			mayor=aux[i]-aux[i+1];
			i++;
		}
	}
	cout<<mayor<<"\t";
	for (int i = 0; i <machine*2 ; ++i)
	{
		cout<<"{"<<aux[i]<<",";
		int contador=1;
		for (int j = 0; j <machine*bateria*2; ++j)
		{
			if(powerbateries[j]!=-1){
				cout<<powerbateries[j]<<",";
				powerbateries[j]=-1;
				contador++;
			}
			if (contador==bateria)
			{
				cout<<"}"<<" ";
				break;
			}
		}
	}
	
cout<<endl;
}

int main(int argc, char *argv[])
{
	Machine m1;
	system("clear");
	int total=atoi(argv[1])*atoi(argv[2])*2;
	//cout<<total<<endl;
	if(total!=argc-3){msgErr();}
	else{
		m1.getmemory(total);
		m1.llenar(argv,total);
		m1.ordenar(total);
		m1.salida(atoi(argv[1]),atoi(argv[2]));
		//m1.imprimir();

	}
	return 0;
}