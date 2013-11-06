#include <iostream> 
using namespace std;
double tripleByValue(double num){
	return num*3;
}
double tripleByReference(double &cnum){
	return cnum=cnum*3;
}

int main(int argc, char const *argv[])
{
	double num;
	double &cnum=num;
	cout<<"Ingresar numero "<<endl;
	cin>>num;
	cout<<"EL triple de "<<num<<" es "<<tripleByValue(num)<<endl;
	//cout<<num<<endl;
	cout<<"EL triple por referencia de "<<num<<" es "<< tripleByReference(cnum)<<" usando alias"<<endl;
	return 0;
}