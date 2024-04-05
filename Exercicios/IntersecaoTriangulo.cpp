#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

int main(){

	int raio = 4;
	
	double AreaTriEqui = ((pow(raio,2))*(sqrt(3)))/4 ;
	double AreaFora = (( PI * pow(raio,2))/6) - AreaTriEqui;
	double ResultFinal = 2* AreaTriEqui + 4 * AreaFora;

	cout <<" O resultado é: " << ResultFinal;
	
	return 0;

}
