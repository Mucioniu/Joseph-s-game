#include "nod.h"

class Lista{
		private:
				Nod *santinela;
				int numarElemente;
		public:
				Lista();
				~Lista();
				Lista(const Lista &);
				Lista& operator=(const Lista&);
				void adaugaSfarsit(const Info&);
				void adaugaPrimul(const Info&);
				void adaugaNod(const Info&, int index);
				void creareLista(int);
				void afisare() ;
				void stergeSfarsit();
				void stergeInceput();
				void stergeIndex(int index);
				void jocJoseph(int nr);
				
};

