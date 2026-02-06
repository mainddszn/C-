
#include <iostream>
#include <string>
#define DIM 10
using namespace std;
struct s_nodo{
	int info;
	string nome;
	s_nodo *next;
};
s_nodo *caricalista(s_nodo *ptesta);
void stampalista(s_nodo *ptesta);
s_nodo *aggiungitesta(s_nodo *ptesta, string nome, int info);
int calcolalun(s_nodo *ptesta);
void aggiungicoda(s_nodo* ptesta , string nome, int info);
s_nodo *rimuovicoda(s_nodo *ptesta);
s_nodo *rimuovitesta(s_nodo *ptesta);
s_nodo *aggiungipos(s_nodo *ptesta, int pos,int info,string nome);
s_nodo *rimuovipos(s_nodo *ptesta, int pos);
int lung(s_nodo *ptesta);
int ricerca(s_nodo *ptesta,string cerca);
int main()
{
	int info2,info,lun;
	string nome2,nome, cerca;
	s_nodo *ptesta = NULL;
	ptesta = caricalista(ptesta);
	ptesta = rimuovitesta(ptesta);
	stampalista(ptesta);
	cout << "\nInserisci nome da cercare: ";
	cin >> nome2;
	int pos = ricerca(ptesta, nome2);
	if(pos != -1) {
		cout << "Trovato alla posizione: " << pos << endl;
	} else {
		cout << "Non trovato" << endl;
	}
	cout << "Lunghezza lista: " << lung(ptesta) << endl;
	cout << "Inserisci posizione e dati per aggiungere: ";
	cin >> info2 >> nome2;
	ptesta = aggiungipos(ptesta, 2, info2, nome2);
	cout << "Lista dopo aggiunta: " << endl;
	stampalista(ptesta);
	cout << "Rimozione dalla coda: " << endl;
	ptesta = rimuovicoda(ptesta);
	stampalista(ptesta);

	return 0;
}

s_nodo *caricalista(s_nodo *ptesta){

	int info;
	string nome;
	
	int s1,s2;
	int i=0;
	do{

		cout<<"vuoi caricare la lista? 1 si 0 no"<<endl;
		cin>>s1;
		if(i==0 && s1>0){
			cout<<"inserisci nome ed info"<<endl;
				cin>>nome;
				cin>>info;
				ptesta=aggiungitesta(ptesta,nome, info);
			
		}
		if(s1>0 && i>0){
			cout<<"in testa o in coda 1 testa 0 coda"<<endl;
			cin>>s2;
			if(s2==0){
				cout<<"inserisci nome ed info"<<endl;
				cin>>nome;
				cin>>info;
				aggiungicoda(ptesta,nome, info);
			}
			else{
				cout<<"inserisci nome ed info"<<endl;
				cin>>nome;
				cin>>info;
				ptesta=aggiungitesta(ptesta,nome, info);
				
			}
		}
		++i;
		
	}while(s1!=0);
	
	return ptesta;
}

void stampalista(s_nodo *ptesta){
	while (ptesta!=NULL){
		cout<<"NOME: "<<ptesta->nome<<endl;
		cout<<"INFO: "<<ptesta->info<<endl;
		ptesta=ptesta->next;
	}
}



s_nodo *aggiungitesta(s_nodo *ptesta,string nome,int info){
	s_nodo *testa2=new s_nodo;
	testa2->info=info;
	testa2->nome=nome;
	testa2->next=ptesta;
	return testa2;
}
void aggiungicoda(s_nodo *ptesta,string nome, int info){
	s_nodo *coda=new s_nodo;
	coda->info=info;
	coda->nome=nome;
		while(ptesta->next != NULL){
		ptesta=ptesta->next;
	}
	ptesta->next=coda;
	coda->next=NULL;
	
	
}

int lung(s_nodo *ptesta){
	int lun=0;
	while(ptesta!=NULL){
		++lun;
		ptesta=ptesta->next;
	}
	return lun;
}
s_nodo *rimuovitesta(s_nodo *ptesta){
	ptesta=ptesta -> next;
	return ptesta;
}

s_nodo *rimuovicoda(s_nodo *ptesta){
	while(ptesta->next->next != NULL){
		ptesta=ptesta->next;
	}
	ptesta->next=NULL;
}

s_nodo *rimuovipos(s_nodo *ptesta, int pos){
	s_nodo *temp=new s_nodo;
	temp=ptesta;
	int i=0;
	int lun;
	lun=lung(ptesta);
	if(pos>lun){
		printf("non possibile");
	}
	else if(pos==0){
		rimuovitesta(ptesta);
	}
	else if(pos==DIM){
		rimuovicoda(ptesta);
	}
	else{
		while(i<pos-1){
			temp=temp->next;
			++i;
		}
		temp->next=temp->next->next;
	}
	return ptesta;
}

s_nodo *aggiungipos(s_nodo *ptesta, int pos,int info,string nome){
	s_nodo *testa1=new s_nodo;
	testa1=ptesta;
	int i=0;
	int lun;
	lun=lung(ptesta);
	if(pos>lun){
		printf("non possibile");
	}
	else if(pos==0){
		aggiungitesta(ptesta,nome,info);
	}
	else if(pos==lun){
		aggiungicoda(ptesta,nome,info);
	}
	else{
		while(i<pos-1){
			testa1=testa1->next;
			++i;
		}
		s_nodo *temp=new s_nodo;
		temp->nome=nome;
		temp->info=info;
		temp->next=testa1->next;
		testa1->next=temp;
	}
	return testa1;
}

int ricerca(s_nodo *ptesta,string cerca){
	int cerco=0;
	
	do{
		if(ptesta!=NULL && ptesta->nome==cerca){
			
			++cerco;
			return cerco;
		}
		ptesta=ptesta->next;
		++cerco;
	}while(ptesta!=NULL);
	return -1;
}



