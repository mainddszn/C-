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
s_nodo *mergesort(s_nodo *ptesta,s_nodo *ptesta2);
void aggiungicoda(s_nodo* ptesta , string nome, int info);



int main()
{
	int info2,info;
	string nome2,nome, cerca;
	
	s_nodo *ptesta=NULL;
	s_nodo *ptesta2=NULL;
	s_nodo *ptesta3= new s_nodo;
	
	ptesta=caricalista(ptesta);
	ptesta2=caricalista(ptesta2);
	
	stampalista(ptesta);
	cout<<endl;
	stampalista(ptesta2);
	
	ptesta3 = mergesort(ptesta, ptesta2);
	cout<<endl;
	stampalista(ptesta3);
	
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

s_nodo *mergesort(s_nodo *ptesta,s_nodo *ptesta2){
	s_nodo *prev=NULL;
	s_nodo *ptemp= new s_nodo;
	s_nodo*ptemp2=new s_nodo;
	s_nodo*ptesta3=new s_nodo;
	ptemp=ptesta;
	ptemp2=ptesta2;
	while(ptemp!=NULL && ptemp!=NULL){
		s_nodo *temp1= new s_nodo;
		if ( ptemp -> info < ptemp2 -> info ) {
			temp1 -> info = ptemp -> info;
			temp1 -> nome = ptemp -> nome;
			ptemp=ptemp->next;
		}
		else {
			temp1 -> info = ptemp -> info;
			temp1 -> nome = ptemp -> nome;
			ptemp2 = ptemp2 -> next;
				
		}
		temp1 -> next = NULL;
		
		if(prev!=NULL){
			prev->next = temp1;
		}
		else{
			ptesta3 = temp1;
		}
		prev = temp1;
	}
	while(ptemp != NULL){
		s_nodo *temp1= new s_nodo;
		temp1 -> info = ptemp -> info;
		temp1 -> nome = ptemp -> nome;
		temp1 -> next = NULL;
		
		
		if(prev!=NULL){
			prev->next = temp1;
		}
		else{
			ptesta3 = temp1;
		}
		prev = temp1;
		ptemp = ptemp -> next;
	}
	while ( ptemp2 != NULL) {
		s_nodo *temp1= new s_nodo;
		temp1 -> info = ptemp2 -> info;
		temp1 -> nome = ptemp2 -> nome;
		temp1 -> next = NULL;
		
		
		if(prev!=NULL){
			prev->next = temp1;
		}
		else{
			ptesta3 = temp1;
		}
		prev = temp1;
		ptemp2 = ptemp2 -> next;
	}
	
	return ptesta3;	
}
