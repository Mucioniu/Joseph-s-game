#include <iostream>
#include <cstring>
#include "Lista.h"
using namespace std;

Lista::Lista()	//constructor fara parametrii
{
	numarElemente = 0;
	santinela = new Nod;
	santinela->urm = santinela;
	santinela->ant = santinela;
}

Lista::~Lista()		//destructor
{
	Nod *p = santinela;
    Nod *q;
    while(p->urm != santinela)
	{
        q = p;
        p = p->urm;
        delete q;        
    }
    delete santinela;
}

Lista::Lista(const Lista &l)	//constructorul de copiere
{
	Nod *p = l.santinela;
    Nod *q;
    while(p->urm != santinela)
	{
        p = p->urm;
        adaugaSfarsit(p->val);       
    }
}

Lista& Lista::operator=(const Lista& l)   //supradefinirea operatorului =
{
	Nod *p = l.santinela;
	if( santinela->urm != santinela)
	{
		Nod *p = santinela;
   		Nod *q;
	    while(p->urm != santinela)
		{
	        q = p;
	        p = p->urm;
	        delete q;        
	    }
	    santinela->urm = santinela;
	    santinela->ant = santinela;
	}
	
	while(p->urm != l.santinela)
		{
	        p = p->urm;
	        adaugaSfarsit(p->val);       
	    }
    
    return *this;
}
void Lista::adaugaSfarsit(const Info& val)    //adauga un nod la finalul listei
{
	Nod *p = new Nod;
	p->val = val;
	if (santinela->urm == santinela)
	{
		santinela->urm = p;
		p->ant = santinela;
		santinela->ant = p;
		p->urm = santinela;
	}
	else
	{
		santinela->ant->urm = p;
		p->ant = santinela->ant;
		santinela->ant = p;
		p->urm = santinela;
	}
	numarElemente++;
}
void Lista::adaugaPrimul(const Info&val)      //adauga un nod la inceputul listei
{
	Nod *p = new Nod;
	p->val = val;
	if (santinela->urm == santinela)
	{
		santinela->urm = p;
		p->ant = santinela;
		santinela->ant = p;
		p->urm = santinela;
	}
	else
	{
		p->urm = santinela->urm;
		santinela->urm->ant = p;
		p->ant = santinela;
		santinela->urm =p;
	
	}
	numarElemente++;
	
}
void Lista::adaugaNod(const Info &val, int index)      //adauga un nod dupa un element ales din lista
{
	Nod *p = new Nod;
	Nod *q;
	p->val = val;
	q = santinela;

	if(index > numarElemente)
	{
		cout<<"Nu exista atatea noduri in lista";
	}
	else
	{
	for (int i = 1 ; i <= index; i++)
		q = q->urm;
	p->urm =q->urm;
	q->urm->ant = p;
	q->urm = p;
	p->ant = q;
	}
	numarElemente++;
	
}
void Lista::creareLista(int n)
{   
	for(int i = 0; i < n; i++)
		{
		    Info val;
		    val.nume = new char[15];
			cout<<"\nNumele copilului este = ";
			cin.get();
			cin.getline(val.nume, 15);
			cout<<"Varsta copilului este= ";
			cin>>val.varsta;
			adaugaSfarsit(val);
		}
}
void Lista::afisare()           
{ 
	int i = 0;
	for( Nod *p = santinela->urm ; p != santinela; p = p->urm)
	{   
		i++;
		cout<<"\nNumele de pe pozitia "<<i<<" este= "<<p->val.nume;
		cout<<"\nVarsta de pe pozitia "<<i<<" este= "<<p->val.varsta;
	}
}
void Lista::stergeSfarsit()        //sterge ultimul element din lista
{
	if( santinela->urm == santinela)
		cout<<"Lista este goala";
	Nod *p = santinela->ant;
	p->ant->urm = santinela;
	santinela->ant = p->ant;
	delete p;
	numarElemente--;
}
void Lista::stergeInceput()        //sterge primul element din lista
{
	if( santinela->urm == santinela)
		cout<<"Lista este goala";
	Nod *p = santinela->urm;
	p->urm->ant = santinela;
	santinela->urm = p->urm;
	delete p;
	numarElemente--;
}
void Lista::stergeIndex(int index)       //sterge un element la alegere din lista
{
	if(index > numarElemente)
	{
		cout<<"Nu exista atatea noduri in lista";
	}
	else
	{
	Nod *p = santinela;
	
	for (int i = 1 ; i <= index; i++)
		p = p->urm;
	p->ant->urm = p->urm;
	p->urm->ant = p->ant;
	delete p;
	numarElemente--;
	}
	
}

//eliminarea copiilor incepand cu primul, din nr in nr elemente 
//pana cand ramane un singur copil in lista 
void Lista::jocJoseph(int nr)    
{
	if (santinela->urm == santinela)
	{
		cout<<"Nu exista copii in lista";
		return;
	}
	while(numarElemente > 1) {
		for (int i = 1; i <= numarElemente && numarElemente > 1; i = i + nr - 1) {
			stergeIndex(i);
		}
		afisare();
		cout<<endl;
	}
	cout<<"A mai ramas doar un copil";
}

