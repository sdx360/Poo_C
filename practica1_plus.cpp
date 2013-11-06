#include <iostream>
#define PI 3.14159
using namespace std;
inline float circleArea(float radio){
 return PI*(radio*radio);
 
}

int main(int argc, char const *argv[])
{
	float radio;
	cout<<"Ingresar el radio del circulo"<<endl;
	cin>>radio;
	cout<<"El area del circulo con radio "<<radio<<" es "<<circleArea(radio)<<endl;
		return 0;
}