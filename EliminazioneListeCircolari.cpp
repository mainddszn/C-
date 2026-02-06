#include <iostream>
#define DIM 10
#include <time.h>
#include <stdlib.h>
using namespace std;
struct s_nodo{
	int num;
	s_nodo *next;
	s_nodo *prev;
};

s_nodo *caricalista(s_nodo *testa, s_nodo *coda);
void stampalista(s_nodo *testa);
s_nodo *eliminazione(s_nodo *testa, int pos);

int main()  {
	srand(time(NULL));	
	s_nodo *testa=NULL;
	s_nodo *coda=NULL;
	int scelta;
	int pos=0;
	do
	{
		system("cls");
		cout<<"SIMONE MAINO 4AITI"<<endl;
		cout<<"1"<<endl;
		cin>>scelta;
		
		
		switch(scelta)
		{
			case 1:
				testa=caricalista(testa,coda);
				stampalista(testa);
				cout<<"inserisci ogni quanti elementi eliminare"<<endl;
				cin>>pos;
				testa=eliminazione(testa,pos);
				break;
			default:
				cout<<"Opzione non valida"<<endl;		
		}
		system("PAUSE");
	} while(scelta!=6); 
	return 0;
}

s_nodo *caricalista(s_nodo *testa,s_nodo *coda){
	s_nodo *temp;
	s_nodo *prev=NULL;
	for(int i=0; i<DIM; ++i) {
		temp=new s_nodo;
		temp->num=rand()%9+1;
		temp->next=NULL;
		temp->prev=NULL;
		if(prev==NULL){
			testa=temp;
		}
		else{
			prev->next=temp;
			temp->prev=prev;
		}
		prev=temp;
		coda=temp;
	}
		coda->next=testa;
		testa->prev=coda;
		return testa;
}

void stampalista(s_nodo *testa){
	s_nodo *temp=testa;
	do{
		cout<<"VOTO: "<<temp->num<<endl;
		temp=temp->next;
	}while(temp!=testa);
	cout<<endl;
}

s_nodo *eliminazione(s_nodo *testa, int pos){
	int lun=10;
	stampalista(testa);	
	while(lun>1){
		for(int i=0;i<pos;++i){
			testa=testa->next;
		}
		s_nodo *temp=new s_nodo;
		s_nodo *temp2=new s_nodo;
		temp->prev=NULL;
		temp->next=NULL;
		temp2->prev=NULL;
		temp2->next=NULL;
		temp=testa->prev;
		temp2=testa->next;
		temp2->prev=temp;
		temp->next=temp2;
		lun--;
		stampalista(temp2);
		testa=temp2;
	}
	return testa;
}

