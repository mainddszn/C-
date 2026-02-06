#include <iostream>
#define DIM 10
#include <time.h>
#include <stdlib.h>
using namespace std;
struct s_cas{
	int num;
	s_cas *next;
	s_cas *prev;
};
s_cas *caricalista(s_cas *testa,s_cas *&coda);
s_cas *aggiungitesta(s_cas *testa,int num);
void stampalista(s_cas *testa);
s_cas* rovescialista(s_cas *testa);
s_cas *lista(s_cas *testa);
void aggiungicoda(s_cas *testa, int num);
void stampalistab(s_cas *coda);


int main()  {
	srand(time(NULL));	
	s_cas *testa=NULL;
	s_cas *coda=NULL;
	int scelta;
	do
	{
		system("cls");
		cout << "\n========================================" << endl;
		cout << "           MENU PRINCIPALE" << endl;
		cout << "========================================\n" << endl;
		cout << "    1) Carica Lista" << endl;
		cout << "    2) Stampa Lista (Inversa)" << endl;
		cout << "    3) Aggiungi in Testa" << endl;
		cout << "    4) Aggiungi in Coda" << endl;
		cout << "    5) Esci" << endl;
		cout << "\n========================================" << endl;
		cout << "Scelta: ";
		cin>>scelta;
		
		
		switch(scelta)
		{
			case 1:
				testa=caricalista(testa,coda);
				stampalista(testa);
    			break;
    		case 2:
    			stampalistab(coda);
    			break;
    		case 3:
				testa=aggiungitesta(testa,rand()%91+10);
				stampalista(testa);
    			break;
			case 4:
				aggiungicoda(testa,rand()%91+10);
				stampalistab(coda);
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

s_cas *caricalista(s_cas *testa,s_cas *&coda){
	s_cas *temp;
	s_cas *prev=NULL;
	for(int i=0; i<DIM; ++i) {
		cout<<"a";
		temp=new s_cas;
		temp->num=rand()%91+10;
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
	}
		coda=temp;
		return testa;
}

s_cas *aggiungitesta(s_cas *testa,int num){
	s_cas *testa2=new s_cas;
	testa2->num=num;
	testa2->next=testa;
	
	return testa2;
}

void aggiungicoda(s_cas *testa,int num){
	s_cas *coda=new s_cas;
	coda->num=num;
		while(testa->next != NULL){
		testa=testa->next;
	}
	testa->next=coda;
	coda->next=testa;
	
	
}

void stampalista(s_cas *testa){
	while(testa!=NULL){
		cout<<"VOTO: "<<testa->num<<endl;
		testa=testa->next;
	}
}
void stampalistab(s_cas *coda){
	while(coda!=NULL){
		cout<<"VOTO: "<<coda->num<<endl;
		coda=coda->prev;
	}
}


