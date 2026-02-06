#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#define DIM 20
using namespace std;

struct s_nodo
{
	int num;
	s_nodo *pnext;
};

s_nodo* caricalista();
void stampalista(s_nodo *ptesta);
s_nodo* fusione(s_nodo *ptesta);
s_nodo* rovescialista(s_nodo *ptesta);

int main()
{
	srand(time(NULL));
	s_nodo *ptesta=new s_nodo;
	s_nodo *ptesta2=new s_nodo;
	
	ptesta=NULL;
	ptesta2=NULL;
	
	ptesta=caricalista();
	cout<<"Lista: "<<endl;
	stampalista(ptesta);
	ptesta2=fusione(ptesta);
	cout<<endl;
	cout<<"Lista >= 60: "<<endl;
	stampalista(ptesta2);
	
	ptesta=rovescialista(ptesta);
	cout<<"Lista invertita: "<<endl;
	stampalista(ptesta);
	ptesta2=rovescialista(ptesta2);
	cout<<"Lista >= 60 invertita: "<<endl;
	stampalista(ptesta2);
	

	
	return 0;
}

s_nodo* caricalista()
{
	s_nodo *ptesta=NULL;
	s_nodo *pprev=NULL;
	
	for(int i=0;i<DIM;i++)
	{
		s_nodo *ptemp=new s_nodo;
		ptemp->num=rand()%91+10;
		ptemp->pnext=NULL;
		if(pprev!=NULL)
		{
			pprev->pnext=ptemp;
		}
		else
		{
			ptesta=ptemp;
		}
		pprev=ptemp;
	}
	return ptesta;
}

void stampalista(s_nodo *ptesta)
{
	while(ptesta!=NULL)
	{
		cout<<"Numero: "<<ptesta->num<<endl;
		ptesta=ptesta->pnext;
	}
	cout<<endl;
}

s_nodo* fusione(s_nodo *ptesta)
{
    s_nodo *ptesta2=NULL;
    s_nodo *pprev=NULL;
    s_nodo *ptemp=ptesta;

    while(ptemp!=NULL)
    {
        if(ptemp->num>=60)
        {
            s_nodo *ptemp2=new s_nodo;
            ptemp2->num=ptemp->num;
            ptemp2->pnext=NULL;
            
            if(pprev != NULL)
            {
            	pprev->pnext=ptemp2;
			}
            else
            {
            	ptesta2=ptemp2;
			}
            pprev=ptemp2;
        }
        ptemp=ptemp->pnext;
    }

    return ptesta2;
}

s_nodo* rovescialista(s_nodo *ptesta)
{
	s_nodo *pprev=NULL;
	s_nodo *curr=ptesta;
    s_nodo *next=NULL;

    while(curr!=NULL)
    {
        next=curr->pnext;
        curr->pnext=pprev;
        pprev=curr;       
        curr=next;       
    }

    return pprev;
}
