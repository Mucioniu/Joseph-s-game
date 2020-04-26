#include <iostream>
#include <cstring>
#include "Lista.h"

using namespace std;

int main() {
	int n;
	cout<<"Introduceti numarul elementelor din lista: ";
	cin>>n;
	Lista L;
	L.creareLista(n);
	L.jocJoseph(3);
	L.afisare();
	return 0;
}
