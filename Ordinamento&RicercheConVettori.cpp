// maindd - GitHub
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define DIM 10
void caricaVett(int vett[]);
void stampaVett(int vett[], int lung);
int caricaVettPar(int vett[]);
int caricavett(int vett[], int n);
void stampavett (int vett[], int n, int lung);
int ricerca1 (int vett[], int cerca, int lung);
int ricerca2 (int vett[], int cerca, int lung);
int ricerca3 (int vett[], int cerca, int lung);
int ricerca_binaria(int vett[], int cerca, int lung);
void bubble_sort (int vett[], int lung);
int cercaMinpos(int vett[],int pos, int lung);
void selectionsort(int vett[],int lung);
void shiftdxparz(int vett[],int pos,int lung);
int insertsort(int vett[]);
int main () {
	int scelta, a, b, c, ris, val, min, pmax, max, gennum, pos, lung, n, lun1, lun2, lun3,lung30, vett1[DIM], vett2[DIM], vett3[DIM], vettes[DIM],lun ; //Dichiaraz<ione variabili
	int vett [DIM];
	bool trovato,num;
	srand(time(NULL));
	//caricaVett(vett);
	lung=DIM;
	
	do
	{
		system("cls");
		cout<<"1. Ricerca binaria"<<endl;
		cout<<"2. Bubble sort"<<endl;
		cout<<"3. Selection sort"<<endl;
		cout<<"4. Insert sort"<<endl;
		cout<<"5. Esci"<<endl;
		cin>>scelta;
		
		
		switch(scelta)
		{

				
			case 1:
				cout<<"ins val"<<endl;
				cin>>val;
				pos=ricerca_binaria(vett, val, lung);
				if(pos==-1)
				{
					cout<<"elemento non trovato"<<endl;
				}else{
					cout<<"elemento trovato nella pos "<<pos<<endl;
				}
				break;

			case 2:
				caricaVett(vett1);
				bubble_sort (vett1, DIM);
				stampaVett(vett1, DIM);				
				break;

			case 3:
				lung=caricaVettPar(vett);
					stampaVett(vett,lung);
				selectionsort(vett,lung);
				stampaVett(vett,lung);
				break;
			case 4:
				
				lung=insertsort(vett);
				stampaVett(vett,lung);
			break;
			
			case 5:
				cout<<"Fine"<<endl;
				break;
			default:
				cout<<"Opzione non valida"<<endl;		
		}
		system("PAUSE");
	} while(scelta!=5); 
	return 0;
}

void caricaVett(int vett[]){
	int i;
	for(i=0; i<DIM; i++){
		cout<<"ins numero"<<endl;
		cin>>vett[i];
	}
}

int caricavett(int vett[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		vett[i]=i+1;
	}
}

void stampaVett(int vett[], int lung){
	int i;
	for(i=0; i<lung; i++){
		cout<<vett[i]<<" ";
	}
	cout<<endl;
}

int caricaVettPar(int vett[])
{
	int lung, num;
	num=0;
	lung=0;
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

void stampavett (int vett[], int n, int lung){
	int i;
	for(i=0; i<n; i++)
	{
		cout<<vett[i]<<" ";
	}
	cout<<endl;
}

int ricerca1 (int vett[], int cerca, int lung)
{
	bool trovato=false;
	int i=0;
	while(i<lung && trovato==false)
	{
		if(vett[i]==cerca)
		{
			trovato=true;
		}else{
			i=i+1;
		}
	}
	
	if(i==lung)
	{
		return-1;
	}else{
		return i;
	}
}

int ricerca2 (int vett[], int cerca, int lung)
{
	int i=0;
	while(i<lung-1 && vett[i]==cerca)
	{
		i=i+3;
	}
	if(vett[i]==cerca)
	{
		return i;
	}else{
		return-1;
	}
}

int ricerca3 (int vett[], int cerca, int lung)
{
	int i=0;
	vett[lung]=cerca;
	while(vett[i]!=cerca)
	{
		i++;
	}
	if(i=DIM)
	{
		return-1;
	}else{
		return i;
	}
}

int ricerca_binaria(int vett[], int cerca, int lung)
{
	int inizio, fine, medio;
	inizio=0;
	fine=DIM-1;
	
	while(fine>=inizio)
	{
		medio=(inizio+fine)/2;
		if(vett[medio]==cerca)
		{
			return medio;
		}else{
			if(vett[medio]>cerca)
			{
				fine=medio-1;
			}else{
				inizio=medio+1;
			}
		}
	}
	return-1;
}



void bubble_sort (int vett[], int lung)
{
	int temp;
	bool scambi=false;
	do{
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
	}while(scambi==true);
}

int cercaMinpos(int vett[],int pos, int lung)
{
	int min;
	min=pos;
	for(int i=pos+1; i<lung; i++)
	{
		if(vett[i]<vett[min]){
			min=i;
		}
	}
	return min;
}

void selectionsort(int vett[],int lung){
	int min,temp;
	for(int i=0;i<lung;i++){
		min=cercaMinpos(vett,i,lung);
		temp=vett[i];
		vett[i]=vett[min];
		vett[min]=temp;
	}
}


void shiftdxparz(int vett[],int pos,int lung){
	for(int i=lung-1;i>=pos;i--){
		vett[i]=vett[i-1];
	}
}

int insertsort(int vett[]){
int i,num,lung;
lung=0;
cout<<"inserisci num"<<endl;
cin>>num;
while(num!=0){
	i=0;
	lung++;
	while(i<lung-1 &&vett[i]<num){
		i++;
	}
	shiftdxparz(vett,i,lung);
	vett[i]=num;
	cout<<"inserisci num"<<endl;
	cin>>num;
	}
	return lung;
}


