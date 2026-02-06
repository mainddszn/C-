// maindd - GitHub
#include <iostream>
#include <string>
using namespace std;
#define DIM 10

struct s_squadra{
    string nome;
    int codice, goal_fatti, goal_subiti;
};

int caricaVett(s_squadra vett[]);
void stampaVett(s_squadra vett[], int lun);
void stampaGoalMagg(s_squadra vett[], int lun);
void cercaSquadra(s_squadra vett[], int lun, int codice);

int main() {
    s_squadra vett[DIM];
    int lun=caricaVett(vett);    
    stampaVett(vett, lun);

    cout<<"squadre con goal fatti > goal subiti: "<<endl;
    stampaGoalMagg(vett, lun);

    int cod;
    cout<<"ins il codice di una squadra da cercare "<<endl;
    cin>>cod;
    cercaSquadra(vett, lun, cod);
    return 0;
}

int caricaVett(s_squadra vett[])
{
	int lun=0;
	bool scelta;
	do
	{
		cout<<"vuoi inserire una squadra? (0: no/1: si) -->"<<endl;
		cin>>scelta;
		cin.ignore();
		if(scelta==true && lun<DIM)
		{
			cout<<"ins nome squadra "<<endl;
			getline(cin, vett[lun].nome);
			cout<<"ins codice squadra "<<endl;
			cin>>vett[lun].codice;
			cout<<"ins goal fatti"<<endl;
			cin>>vett[lun].goal_fatti;
			cout<<"ins goal subiti "<<endl;
            cin>>vett[lun].goal_subiti;
			cin.ignore();
			lun++;
		}
	}while(scelta==true && lun<DIM);
	return lun;
}

void stampaVett(s_squadra vett[], int lun)
{
	for(int i=0; i<lun; i++)
	{
			cout<< "Nome: "<<vett[i].nome<<" codice: "<<vett[i].codice<<" goal fatti: "<<vett[i].goal_fatti<<" goal subiti: "<<vett[i].goal_subiti<<endl;
	}
}

void stampaGoalMagg(s_squadra vett[], int lun)
{
    bool trovate=false;
    for(int i= 0; i<lun; i++)
    {
        if (vett[i].goal_fatti>vett[i].goal_subiti)
        {
            cout<<"Nome: "<< vett[i].nome<<" | codice: "<<vett[i].codice<<" | goal fatti: "<<vett[i].goal_fatti<<" | goal subiti: "<< vett[i].goal_subiti<<endl;
            trovate = true;
        }
    }
    if (trovate==false) {
        cout<<"Nessuna squadra con goal fatti > goal subiti."<<endl;
    }
}

void cercaSquadra(s_squadra vett[], int lun, int codice)
{
    bool trovato=false;
    for(int i=0; i<lun; i++)
	{
        if (vett[i].codice==codice)
		{
            cout<<"Nome: "<<vett[i].nome<<" goal fatti: "<<vett[i].goal_fatti<< " goal subiti: "<<vett[i].goal_subiti<<endl;
            trovato=true;
            break;
        }
    }
    if (trovato==false) {
        cout<<"nessuna squadra trovata"<<endl;
    }
}
