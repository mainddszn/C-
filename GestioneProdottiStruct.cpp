// maindd - GitHub
#include <iostream>
#include <string>
using namespace std;
#define DIM 10

struct s_prodotto{
	string des;
	int qt, anno;
};

int caricaVett(s_prodotto vett[]);
void ordinaVett (s_prodotto vett[], int lun);
void stampaVett(s_prodotto vett[], int lun);
int salvaScaduti(s_prodotto vett[], int lun, s_prodotto scaduti[]);
void stampaScaduti(s_prodotto scaduti[], int num_scaduti);

int main(){
	s_prodotto vett[DIM], scaduti [DIM];
	int lun=caricaVett(vett);
	
	ordinaVett (vett, lun);
	stampaVett(vett, lun);
	
	int num_scaduti=salvaScaduti(vett, lun, scaduti);
	stampaScaduti(scaduti, num_scaduti);	
	return 0;
}

int caricaVett(s_prodotto vett[])
{
	int lun=0;
	bool scelta;
	do
	{
		cout<<"vuoi inserire un prodotto? (0: no-1: si) -->"<<endl;
		cin>>scelta;
		cin.ignore();
		if(scelta==true && lun<DIM)
		{
			cout<<"ins descrizione prodotto"<<endl;
			getline(cin, vett[lun].des);
			cout<<"ins quantita' "<<endl;
			cin>>vett[lun].qt;
			cout<<"ins anno scadenza"<<endl;
			cin>>vett[lun].anno;
			cin.ignore();
			lun++;
		}
	}while(scelta==true && lun<DIM);
	return lun;
}


void ordinaVett (s_prodotto vett[], int lun)
{
	s_prodotto temp;
	bool scambia;
	do{
		scambia=false;
		for(int i=0; i<lun-1; i++)
		{
			if(vett[i].qt<vett[i+1].qt)
			{
				temp=vett[i];
				vett[i]=vett[i+1];
				vett[i+1]=temp;
				scambia=true;
			}
		}	
	}while(scambia==true);	
}

void stampaVett(s_prodotto vett[], int lun)
{
	for(int i=0; i<lun; i++)
	{
		cout<< "Descrizione: "<<vett[i].des<<" quantita': "<<vett[i].qt<<"scadenza: "<<vett[i].anno;
	}
}

int salvaScaduti(s_prodotto vett[], int lun, s_prodotto scaduti[])
{
	int k=0;
	for(int i=0; i<lun; i++)
	{
		if(vett[i].anno<2024)
		{
			scaduti[k++]=vett[i];
		}
	}
	return k;
}

void stampaScaduti(s_prodotto scaduti[], int num_scaduti) 
{
	if(num_scaduti==0)
	{
		cout<<"nessun prodotto scelto"<<endl;
	}else{
		for(int i=0; i<num_scaduti; i++)
		{
			cout<<" descrizione: "<<scaduti[i].des<<" quantita': "<<scaduti[i].qt<<" scadenza: "<<scaduti[i].anno<<endl;
		}
	}
}
