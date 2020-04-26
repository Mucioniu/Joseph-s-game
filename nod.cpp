#include "nod.h"
#include <iostream>
#include <cstring>
using namespace std;

Nod::Nod()
{ 
	urm = NULL;
	ant = NULL;
}
Nod::~Nod()
{  
}

Nod::Nod(const Nod &p)
{
	val = p.val;
	ant = p.ant;
	urm = p.urm;
}

Nod& Nod::operator=(const Nod &p)
{
	val = p.val;
	ant = p.ant;
	urm = p.urm;
	return *this;
}






