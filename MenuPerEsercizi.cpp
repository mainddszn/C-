#include <iostream>
using namespace std;

int main() {
    int scelta;
    
    do {
        system("cls");
        cout << "\n=== MENU ===" << endl;
        cout << " 1) Esercizio 1" << endl;
        cout << " 2) Esci" << endl;
        cout << "=============\n" << endl;
        cout << "Scelta: ";
        
        cin >> scelta;
        cout << endl;
        
        switch(scelta) {
            case 1:
                // es 1 ecc...
                break;
            case 2:
                cout << "Fine" << endl;
                break;
            default:
                cout << "Opzione non valida" << endl;
        }
        
        system("PAUSE");
    } while(scelta != 2);
    
    return 0;
}