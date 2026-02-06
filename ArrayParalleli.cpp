// maindd - GitHub
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#define DIM 3
#define DIM2 20
using namespace std;
int CaricaVettPar (string vett[], int vett2[]);
void StampaVettPar (string vett[], int vett2[], int lun);
void bubble_sort (string vett[], int vett2[], int lun);
void generaArray(int vett[]);
int creaFrequenze(int orig[], int dist[], int freq[]);
void trovaPiuComuni(int dist[], int freq[], int dimfreq);
void stampaArray(int vett[], int dim);
int CaricaVettParRadio (string vett[], int vett2[], string vett_radio[]);
void StampaVettParRadio (string vett[], int vett2[], string vett_radio[], int lun);
int canzoneLunga (string vett[], int vett2[], int lun);
int canzoneCorta (string vett[], int vett2[], int lun);
int mediaCanzoni (string vett[], int vett2[], int lun);
int CaricaVettParMoto (string vett[], int vett2[], string vett_moto[]);
void StampaVettParMoto (string vett[], int vett2[], string vett_moto[], int lun);
int cilindrataMax (string vett[], int vett2[], int lun);
void stampaCognomeMoto (string vett_moto[], string cognome_ricerca, int lun, string vett[]);
int CaricaVettParViaggi (string vett[], int vett2[], int vett3[]);
void StampaVettParViaggi (string vett[], int vett2[], int vett3[], int lun);
int sommaPacchettiM (int vett2[], int vett3[], int mese, int lun);
void tourOperatorMese (string vett[], int vett2[], int vett3[], int lun, string vett_tourOperator);
void venditeDecresc (int vett3[], int lun);

int main () 
{
	int scelta, vett2[DIM], lun, orig[DIM2], dist[DIM2], freq[DIM2], dimfreq, arrayCas[DIM2], max, min, med, vett3[DIM], mese, s;	
	string vett[DIM];
	string vett_radio[DIM];
	string vett_moto[DIM];
	string vett_cognome[DIM];
	string vett_tourOperator [DIM];
	do
	{
	    system("cls");
		cout<<"1. Nome e data di nascita studenti"<<endl;
		
		cout<<"2. Num casuali e freq"<<endl;
		
		cout<<"3. Radio"<<endl;
		
		cout<<"4. Concessionario moto"<<endl;
		
		cout<<"5. Tour operator"<<endl;
		
		cout<<"6. Fine"<<endl;
		
		cin>>scelta;
		
		switch(scelta)
		{
			case 1:
				lun=CaricaVettPar (vett, vett2);
				StampaVettPar (vett, vett2, lun);
				
				bubble_sort (vett, vett2, lun);
				StampaVettPar (vett, vett2, lun);
				break;
				
			case 2:
				generaArray(orig);	
				stampaArray(orig, DIM2);
					
				dimfreq=creaFrequenze(orig, dist, freq);
				cout<<"val distinti e frequenze: "<<endl;
				for(int i=0; i<dimfreq; i++)
				{
					cout<<"val "<<dist[i]<<" freq: "<<freq[i]<<endl;
				}
				
				cout<<"i 3 numeri piu' freq sono: "<<endl;
				trovaPiuComuni(dist, freq, dimfreq);				
				break;
				
			case 3:
				lun=CaricaVettParRadio (vett, vett2, vett_radio);
				StampaVettParRadio (vett, vett2, vett_radio, lun);
				
				max=canzoneLunga (vett, vett2, lun);
				cout<<"la canzone piu' lunga dura: "<<max<<" secondi"<<endl;
				
				min=canzoneCorta (vett, vett2, lun);
				cout<<"la canzone piu' corta dura: "<<min<<" secondi"<<endl;
				
				med=mediaCanzoni (vett, vett2, lun);
				cout<<"la durata media e' "<<med<<" secondi"<<endl;
				break;
				
			case 4:
				{
				lun=CaricaVettParMoto (vett, vett2, vett_moto);
				StampaVettParMoto (vett, vett2, vett_moto, lun);
				
				max=cilindrataMax (vett, vett2, lun);
				for(int i=0; i<lun; i++)
				{
					if(max==vett2[i])
					{
						cout<<"targa/e moto con cilindrata massima: "<<vett[i]<<endl;
					}
				}
				
				string cognome_ricerca;
				cout<<"ins cognome proprietario moto "<<endl;
				cin>>cognome_ricerca;
				stampaCognomeMoto (vett_moto, cognome_ricerca, lun, vett);			
				break;
				}
			
			case 5:
				{				
				lun=CaricaVettParViaggi (vett, vett2, vett3);
				StampaVettParViaggi (vett, vett2, vett3, lun);
				
				cout<<"ins mese del quale si vuole sapere importo totale: "<<endl;
				cin>>mese;
				s=sommaPacchettiM (vett2, vett3, mese, lun);
				cout<<"la somma dei pacchetti venduti nel mese "<<mese<<" e' di "<<s<<" euro"<<endl;
				
				string vett_tourOperator;
				cout<<"ins nome tour operator del quale si vuole sapere l'importo in ogni mese "<<endl;
				cin>>vett_tourOperator;
				tourOperatorMese (vett, vett2, vett3, lun, vett_tourOperator);
				
				venditeDecresc (vett3, lun);
				StampaVettParViaggi (vett, vett2, vett3, lun);
				}				
				break;
					
			case 6:
				cout<<"Fine"<<endl;
				break;
				
			default:
				cout<<"Opzione non esistente"<<endl;
				break;
		}
		system("PAUSE");
	}while(scelta!=6);
}

int CaricaVettPar (string vett[], int vett2[])
{
	int lun=0;
	string nom;
	do{
		cout<<"ins nome studente"<<endl;
		cin>>nom;
		if(nom!="n")
		{
			vett[lun]=nom;
			cout<<"ins data di nascita"<<endl;
			cin>>vett2[lun];
			lun++;
		}
	}while(nom!="n" && lun<DIM);
	return lun;
}

void StampaVettPar (string vett[], int vett2[], int lun)
{
	for(int i=0; i<lun; i++)
	{
		cout<<"studente: "<<vett[i]<<endl;
		cout<<"data di nascita: "<<vett2[i]<<endl;

	}
	cout<<endl;
}

void bubble_sort (string vett[], int vett2[], int lun)
{
	int temp, i;
	string temp1;
	bool scambi=false;
	do{
		scambi=false;
		for(int i=0; i<lun-1; i++)
		{
			if(vett2[i]>vett2[i+1])
			{
				temp=vett2[i];
				vett2[i]=vett2[i+1];
				vett2[i+1]=temp;
				scambi=true;
				temp1=vett[i];
				vett[i]=vett[i+1];
				vett[i+1]=temp1;
			}
		}
	}while(scambi==true);
}

void generaArray(int vett[])
{
	for(int i=0; i<DIM2; i++)
	{
		vett[i]=rand()%10+1;
	}
}

void stampaArray(int vett[], int dim)
{
	for(int i=0; i<dim; i++)
	{
		cout<<vett[i]<<" ";
	}
	cout<<endl;
}

int creaFrequenze(int orig[], int dist[], int freq[])
{
	int dim=0;
	for(int i=0; i<DIM2; i++)
	{
		bool trovato=false;
		for(int y=0; y<dim; y++)
		{
			if(orig[i]==dist[y])
			{
				freq[y]++;
				trovato=true;				
			}
		}
		if(trovato==false)
		{
			dist[dim]=orig[i];
			freq[dim]=1;
			dim++;
		}
	}
	return dim;
}

void trovaPiuComuni(int dist[], int freq[], int dimfreq)
{
	for(int i=0; i<dimfreq-1; i++)
	{
		for(int y=i+1; y<dimfreq; y++)
		{
			if(freq[i]<freq[y])
			{
				int temp=freq[i];
				freq[i]=freq[y];
				freq[y]=temp;
				
				int temp2=dist[i];
				dist[i]=dist[y];
				dist[y]=temp2;
			}
		}
	}
	int max;
	if(dimfreq<3)
	{
		max=dimfreq;
	}else{
		max=3;
	}
	for(int i=0; i<max; i++)
	{
		cout<<"val: "<<dist[i]<<", freq: "<<freq[i]<<endl;
	}
}

int CaricaVettParRadio (string vett[], int vett2[], string vett_radio[])
{
	int lun=0;
	string canz, nom;
	do{
		cout<<"ins nome canzone"<<endl;
		cin>>canz;
		if(canz!="n")
		{
			vett[lun]=canz;
			cout<<"ins nome cantante"<<endl;
			cin>>nom;
			vett_radio[lun]=nom;
			cout<<"ins durata (in secondi) della canzone"<<endl;
			cin>>vett2[lun];
			lun++;
		}
	}while(canz!="n" && lun<DIM);
	return lun;
}

void StampaVettParRadio (string vett[], int vett2[], string vett_radio[], int lun)
{
	for(int i=0; i<lun; i++)
	{
		cout<<"canzone: "<<vett[i]<<endl;
		cout<<"cantante: "<<vett_radio[i]<<endl;
		cout<<"durata: "<<vett2[i]<<endl;
	}
	cout<<endl;
}

int canzoneLunga(string vett[], int vett2[], int lun)
{
	int max=vett2[0];
	for(int i=1; i<lun; i++)
	{
		if(vett2[i]>max)
		{
			max=vett2[i];
		}		
	}
	return max;
}

int canzoneCorta (string vett[], int vett2[], int lun)
{
	int min=vett2[0];
	for(int i=1; i<lun; i++)
	{
		if(vett2[i]<min)
		{
			min=vett2[i];
		}		
	}
	return min;
}

int mediaCanzoni (string vett[], int vett2[], int lun)
{
	int s=0, m, i;
	for(i=0; i<lun; i++)
	{
		s=s+vett2[i];
	}
	m=s/i;
	return m;
}

int CaricaVettParMoto (string vett[], int vett2[], string vett_moto[])
{
	int lun=0;
	string targa, cogn;
	do{
		cout<<"ins targa"<<endl;
		cin>>targa;
		if(targa!="n")
		{
			vett[lun]=targa;
			cout<<"ins cognome proprietario"<<endl;
			cin>>cogn;
			vett_moto[lun]=cogn;
			cout<<"ins cilindrata moto"<<endl;
			cin>>vett2[lun];
			lun++;
		}
	}while(targa!="n" && lun<DIM);
	return lun;
}

void StampaVettParMoto (string vett[], int vett2[], string vett_moto[], int lun)
{
	for(int i=0; i<lun; i++)
	{
		cout<<"targa: "<<vett[i]<<endl;
		cout<<"proprietario: "<<vett_moto[i]<<endl;
		cout<<"cilindrata: "<<vett2[i]<<endl;
	}
	cout<<endl;
}

int cilindrataMax (string vett[], int vett2[], int lun)
{
	int max=vett2[0];
	for(int i=1; i<lun; i++)
	{
		if(vett2[i]>max)
		{
			max=vett2[i];
		}		
	}
	return max;
}

void stampaCognomeMoto (string vett_moto[], string cognome_ricerca, int lun, string vett[])
{
	bool trovato=false;
	for(int i=0; i<lun; i++)
	{
		if(cognome_ricerca==vett_moto[i])
		{
			cout<<"targa della moto di "<<cognome_ricerca<<":"<<vett[i]<<endl;
			trovato=true;
		}
	}
	if(trovato==false)
	{
		cout<<"nessuna moto trovata"<<endl;
	}
}

int CaricaVettParViaggi (string vett[], int vett2[], int vett3[])
{
	int lun=0;
	string to;
	do{
		cout<<"ins mese"<<endl;
		cin>>vett2[lun];
		cout<<"ins tour operator"<<endl;
		cin>>to;
		if(to!="n")
		{
			vett[lun]=to;
			cout<<"ins importi pacchetti"<<endl;
			cin>>vett3[lun];			
			lun++;
		}
	}while(to!="n" && lun<DIM);
	return lun;
}

void StampaVettParViaggi (string vett[], int vett2[], int vett3[], int lun)
{
	for(int i=0; i<lun; i++)
	{
		cout<<"mese: "<<vett2[i]<<endl;
		cout<<"tour operator: "<<vett[i]<<endl;
		cout<<"importi pacchetti: "<<vett3[i]<<endl;
	}
	cout<<endl;
}

int sommaPacchettiM (int vett2[], int vett3[], int mese, int lun)
{
	int s=0;
	for(int i=0; i<lun; i++)
	{
		if(mese==vett2[i])
		{
			s=s+vett3[i];
		}
	}
	return s;
}

void tourOperatorMese (string vett[], int vett2[], int vett3[], int lun, string vett_tourOperator)
{
	for(int i=0; i<lun; i++)
	{
		if(vett_tourOperator==vett[i])
		{
			cout<<"questo tour operator al mese "<<vett2[i]<<" ha guadagnato in pacchetti venduti "<<vett3[i]<<" euro"<<endl;;
		}
	}
}

void venditeDecresc (int vett3[], int lun)
{
	for(int i=0; i<lun-1; i++)
	{
		for(int y=0; y<lun-1; y++)
		{
			if(vett3[y]<vett3[y+1])
			{
				int temp=vett3[y];
				vett3[y]=vett3[y+1];
				vett3[y+1]=temp;
			}
		}
	}
}
