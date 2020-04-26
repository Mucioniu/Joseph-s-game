#include <iostream>
#include "Info.h"
using namespace std;

class Nod{
	public:
		Info val;
		Nod *urm, *ant;
		Nod();
		~Nod();
		Nod(const Nod &);
		Nod& operator=(const Nod&);

};


