#include <iostream>
using namespace std;

int main() {
    int continuar;

    do {
        int num1, num2;

        cout << "Escolha algum numero: " << endl;
        cout << ">> ";
        cin >> num1;

        cout << "Escolha outro numero: " << endl;
        cout << ">> ";
        cin >> num2;

        if (num1 > num2) {
            cout << "A sequencia de "<< num1<<" até "<< num2 << " é: ";
            for (int i = num1; i >= num2; i--) {
                cout << i << " ";
            }
            cout << endl;
            } else if (num1 == num2) {
                int fat = 1;

                for (int i = 1; i <= num1; i++) {
                    fat *= i;
                }
                cout << "O fatorial de " << num1 << " é: " << fat << endl;
                
        } else {
            
            cout <<"\n"<< num1 << " é menor que " << num2<<endl;
            
        }

        cout << "\nDeseja tentar outro numero?\n[1] - Sim\n[2] - Não.\n>> ";
        
        cin >> continuar;
        
    } while (continuar == 1);

    return 0;
}
