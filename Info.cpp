#include "Info.h"
#include <iostream>
#include <cstring>
using namespace std;
Info::Info()
{
	varsta = 0;
	nume = NULL;
}

Info::~Info()
{   
	if( nume != NULL)
	delete [] nume;	
}
Info& Info::operator=(const Info &p)
{
	varsta=p.varsta;
	if(nume != NULL)
		delete [] nume;
	nume = new char[strlen(p.nume)+1];
	strcpy(nume, p.nume);
	return *this;
}

Info::Info( const Info &p)
{   
  *this=p;
}

int Info::get_varsta() const
{
	return varsta;
}


