// maindd - GitHub
#include <iostream>
#include <time.h>
using namespace std;
#define DIM 20
#define DIM2 31
void calcolafrequenze(int vett[], int freq[], int lun);
void casuali(int vett[], int lun);
void stampavett(int vett[], int lun);
void ordinadecrescente(int freq[], int numeri[], int lun);
void trovapiucomuni(int numeri[],int freq[]);

int main()
{
    srand(time(NULL));
    
    int vett[DIM];
    int freq[DIM2] = {0}; 
    int numeri[DIM2];
    
    for (int i = 0; i <= DIM2-1; i++) {
        numeri[i] = i;
    }
    
    casuali(vett, DIM);
    calcolafrequenze(vett, freq, DIM); 
    cout << "Array originale:"<<endl;
    stampaVett(vett, DIM);
    cout << "Array con numeri e frenquenze:"<<endl;
    stampaVett(numeri, DIM2);
    stampaVett(freq, DIM2);
    cout << "Frequenze ordinate in modo decrescente:"<<endl;
    ordinadecrescente(freq, numeri, DIM2); 
    stampaVett(numeri, DIM2);
    stampaVett(freq, DIM2);
    trovapiucomuni(numeri, freq);
    return 0;
}

void casuali(int vett[], int lun)
{
    for (int i = 0; i < lun; i++)
    {
        vett[i] = rand() % 31; 
    }
}

void calcolafrequenze(int vett[], int freq[], int lun)
{
    for (int i = 0; i < lun; i++) {
        freq[vett[i]]++;
    }
}

void stampaVett(int vett[], int lun)
{
    for (int i = 0; i < lun; i++)
    {
        cout << vett[i] << " ";
    }
    cout << endl;
}

void ordinadecrescente(int freq[], int numeri[], int lun)
{
   int temp,temp2;
    for (int i = 0; i < lun - 1; i++) 
    {
        for (int j = 0; j < lun - i - 1; j++)
        {
            if (freq[j] < freq[j + 1]) 
            {
                
                temp = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = temp;
                
                
                temp2 = numeri[j];
                numeri[j] = numeri[j + 1];
                numeri[j + 1] = temp2;
            }
        }
    }
}

void trovapiucomuni(int numeri[],int freq[])
{   
    
    for(int i = 0; i<3;i++)
    {   
        
        cout<<"il "<<i+1<<" numero e' "<< numeri[i]<<" uscito "<<freq[i]<<" volte"<<endl;
    }
}
