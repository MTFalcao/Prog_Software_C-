#include <iostream>
using namespace std;

int main()
{
    
long int tamFibo;
double num1=0, num2=1, seqFibo = 0;

cout << "Determine o tamanho da sequencia de fibonacci: "<< endl;
cout << ">> ";
cin >> tamFibo;


cout << "\nSequencia de Fibonacci: "<< num1 << " " << num2<< " ";

for(int i = 2; i < tamFibo; i++){
    
    seqFibo = num1 + num2;
    cout << seqFibo << " ";
    num1 = num2;
    num2 = seqFibo;
    
    }
    
if (tamFibo >= 2){
  double regraOuro = num2/num1;
  cout << "\n\nA proporção áurea dessa sequencia é: "<< regraOuro;
}

    return 0;
}
