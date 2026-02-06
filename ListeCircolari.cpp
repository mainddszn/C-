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
s_cas *caricalista(s_cas *testa,s_cas *coda);
s_cas *aggiungitesta(s_cas *testa,int num);
void stampalista(s_cas *testa);
s_cas* rovescialista(s_cas *testa);
s_cas *lista(s_cas *testa);
s_cas *aggiungicoda(s_cas *coda,int num);
void stampalistab(s_cas *coda);
s_cas *insCoda(s_cas *coda,int num);
s_cas *insTesta(s_cas *testa,int num);
s_cas *insPos(s_cas *testa,s_cas *coda, int pos,int num);
int lung(s_cas *testa);

int main()  {
	srand(time(NULL));	
	s_cas *testa=NULL;
	s_cas *coda=NULL;
	int num,pos;
	int scelta;
	do
	{
		system("cls");
		cout << "\n";
		cout << "╔════════════════════════════╗" << endl;
		cout << "║         CIRCOLARE          ║" << endl;
		cout << "╠════════════════════════════╣" << endl;
		cout << "║  1) Carica Lista           ║" << endl;
		cout << "║  2) Stampa al Contrario    ║" << endl;
		cout << "║  3) Aggiungi in Coda       ║" << endl;
		cout << "║  4) Aggiungi in Testa      ║" << endl;
		cout << "║  5) Inserisci in Posizione ║" << endl;
		cout << "║  6) Esci                   ║" << endl;
		cout << "╚════════════════════════════╝" << endl;
		cout << "\nScelta: ";
		cin >> scelta;
		cout << "\n";
		
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
    			cout<<"inserisci num"<<endl;
    			cin>>num;
    			coda=aggiungicoda(coda,num);
    			stampalista(testa);
    			cout<<endl;
    			stampalistab(coda);
    			break;
			case 4:
				cout<<"inserisci num"<<endl;
    			cin>>num;
    			testa=aggiungitesta(testa,num);
    			stampalista(testa);
    			cout<<endl;
    			stampalistab(coda);
				break;
			case 5: 
				cout<<"inserisci num"<<endl;
    			cin>>num;
				cout<<"inserisci in che posizione inserire"<<endl;
				cin>>pos;
				testa=insPos(testa,coda,pos,num);
				stampalista(testa);
				cout<<endl;
				stampalistab(coda);
				break;
			case 6:
				cout<<"Fine"<<endl;
				break;
			default:
				cout<<"Opzione non valida"<<endl;		
		}
		system("PAUSE");
	} while(scelta!=6); 
	return 0;
}

s_cas *caricalista(s_cas *testa,s_cas *coda){
	s_cas *temp;
	s_cas *prev=NULL;
	for(int i=0; i<DIM; ++i) {
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
		coda=temp;
	}
		coda->next=testa;
		testa->prev=coda;
		return testa;
}

s_cas *aggiungitesta(s_cas *testa,int num){
	s_cas *testa2=new s_cas;
	s_cas *temp=testa->next;
	testa2->prev=NULL;
	testa2->next=NULL;
	testa2->num=num;
	testa2->next=testa;
	testa->prev=testa2;
	testa2->prev=temp;
	temp->next=testa2;
	return testa2;
}

s_cas *aggiungicoda(s_cas *coda,int num){
	s_cas *temp=new s_cas;
	s_cas *temp2=coda->prev;
	temp->next=NULL;
	temp->prev=NULL;
	temp->num=num;
	coda->next=temp;
	temp->prev=coda;
	temp2->prev=temp;
	temp->next=temp2;
	return temp;
	
}

void stampalista(s_cas *testa){
	s_cas *temp=testa;
	do{
		cout<<"VOTO: "<<temp->num<<endl;
		temp=temp->next;
	}while(temp!=testa);
	cout<<endl;
}

void stampalistab(s_cas *coda){
	s_cas *temp=coda;
	do{
		cout<<"VOTO: "<<temp->num<<endl;
		temp=temp->prev;
	}while(temp!=coda);
	cout<<endl;
}

s_cas *insPos(s_cas *testa,s_cas *coda, int pos,int num){
	s_cas *testa1=new s_cas;
	testa1=testa;
	int i=0;
	int lun;
	lun=lung(testa);
	if(pos>lun){
		printf("non possibile /n");
	}
	else if(pos==0){
		testa=aggiungitesta(testa,num);
	}
	else if(pos==lun){
		coda=aggiungicoda(coda,num);
	}
	else{
		while(i<pos-1){
			testa1=testa1->next;
			++i;
		}
		s_cas *temp=new s_cas;
		s_cas *temp2=new s_cas;
		temp->next=NULL;
		temp->prev=NULL;
		temp2->next=NULL;
		temp2->prev=NULL;
		temp->num=num;
		temp2=testa1->next;
		temp->next=temp2;
		temp->prev=testa1;
		testa1->next=temp;
		temp2->prev=temp;
	}
	return testa;
}

int lung(s_cas *testa){
	int lun=0;
	while(testa!=NULL){
		++lun;
		testa=testa->next;
	}
	return lun;
}


