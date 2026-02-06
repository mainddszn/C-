// maindd - GitHub
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define DIM 30
int caricaVettPar(int vett[]);
void stampaVett(int vett[], int lung);
void bubble_sort(int vett[], int lung);
bool strettCresc(int vett[], int lung);
int unisciVett(int vett[], int lung, int vett2[], int lung2, int vett3[]);
int caricaVettMax10(int vett[], int numn);
bool duplicatiOmissioni (int vett[], int lung10);


int main () {
	int scelta, vett[DIM], lung, vero, vett2[DIM], lung2, vett3[DIM*2], lung3, numn, lung10, contr;
	
	do
	{
	    system("cls");
		cout<<"1. Vettore strettamente crescente"<<endl;
		
		cout<<"2. Fusione e ordine 2 vettori"<<endl;
		
		cout<<"3. Vettore no duplicati no omissioni"<<endl;
		
		cout<<"4. Esci"<<endl;
		
		cin>>scelta;
		
		switch(scelta)
		{
			case 1:
				lung=caricaVettPar(vett);
				stampaVett(vett, lung);	
				bubble_sort(vett, lung);	
				stampaVett(vett, lung);
				vero=strettCresc(vett, lung);
				if(vero==true)
				{
					cout<<"vettore strettamente crescente"<<endl;
				}else{
					cout<<"non e' strettamente crescente"<<endl;
				}	
				break;
				
			case 2:
				lung=caricaVettPar(vett);
				stampaVett(vett, lung);
				bubble_sort(vett, lung);
				stampaVett(vett, lung);
				lung2=caricaVettPar(vett2);
				stampaVett(vett2, lung2);
				bubble_sort(vett2, lung2);
				stampaVett(vett2, lung2);
				lung3=unisciVett(vett, lung, vett2, lung2, vett3);
				bubble_sort(vett3, lung3);
				cout<<"vettore unito e ordinato:"<<endl;
				stampaVett(vett3, lung3);
				break;
			
			case 3:				
				cout<<"ins num di num"<<endl;
				cin>>numn;
				while(numn>10)
				{
					cout<<"ins num di num"<<endl;
					cin>>numn;
				}
				
				lung10=caricaVettMax10(vett, numn);
				stampaVett(vett, lung10);
				bubble_sort(vett, lung10);
				stampaVett(vett, lung10);
				contr=duplicatiOmissioni(vett, lung10);
				if(contr==true)
				{
					cout<<"True"<<endl;
				}else{
					cout<<"False"<<endl;
				}
				break;
				
			case 4: 
				cout<<"Fine"<<endl;
				break;
			default:
				cout<<"Opzione non valida"<<endl;		
		}
		system("PAUSE");
	}
	while(scelta!=4);
	return 0;
}

int caricaVettPar(int vett[])
{
	int lung=0, num;
	num=0;
	do{
		cout<<"ins num"<<endl;
		cin>>num;
		
		if(num!=0)
		{
			vett[lung]=num;
			lung++;
		}
	}while(num!=0 && lung<DIM);
	return lung;
}

void stampaVett(int vett[], int lung){
	int i;
	for(i=0; i<lung; i++){
		cout<<vett[i]<<" ";
	}
	cout<<endl;
}

void bubble_sort(int vett[], int lung)
{
	int temp;
	bool scambi=false;
	do
	{
		scambi=false;
		for(int i=0; i<lung-1; i++)
		{
			if(vett[i]>vett[i+1])
			{
				temp=vett[i];
				vett[i]=vett[i+1];
				vett[i+1]=temp;
				scambi=true;
			}
		}
	}
	while(scambi==true);
}

bool strettCresc(int vett[], int lung)
{
	bool vero;
	vero=true;
	for(int i=0; i<lung-1; i++)
	{
		if(vett[i]==vett[i+1])
		{
			vero=false;
		}
	}
	
	return vero;
}

int unisciVett(int vett[], int lung, int vett2[], int lung2, int vett3[])
{
	for(int i=0; i<lung; i++)
	{
		vett3[i]=vett[i];
	}
	for(int y=0; y<lung2; y++)
	{
		vett3[lung+y]=vett2[y];
	}
	return lung+lung2;
}

int caricaVettMax10 (int vett[], int numn)
{
	int num, lung10=0;
	for(int i=0; i<numn; i++)
	{
		cout<<"ins num"<<endl;
		cin>>num;
		vett[i]=num;
		lung10++;
	}
	return lung10;
}

bool duplicatiOmissioni(int vett[], int lung10)
{
	int i=0;
	bool controllo=true;
	while(controllo==true && i<lung10-1)
	{
		if(vett[i]==vett[i+1] || vett[i+1]-vett[i]!=1)
		{
			controllo=false;
		}
		i++;			
	}
	return controllo;
}

