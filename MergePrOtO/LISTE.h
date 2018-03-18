#include "VECTOR.h"
#include "VECT_DE_VECT.h"

struct lst_vedeve
{
    VECT_DE_VECT vv;
    int id;
    lst_vedeve* nxt;
};

struct lst_ve
{
    VECTOR v;
    int id;
    lst_ve* nxt;
};

struct lst_mat
{
    int** m;
    int id;
    lst_mat* nxt;
};

class lista_elemente
{
	void* p;
	int nr_elemente;
public:
	VECT_DE_VECT& operator[] (int i);
	int get_nr_elemente(){return nr_elemente;}
	void push ();	///ADAUGA ELEMENT LA SFARSIT, CRESTE NR DE ELEMENTE, MODIFICA POINTERUL ELEMENTULUI PRECEDENT
	void actualizare_nr_elemente(int x);	///CIRCULA PANA LA ULTIMUL ELEMENT SI ACTUALIZEAZA
	void citire_tastatura();
	void citire_fisier ();		///NUME FISIER, CITIRE N, CITIRE MATRICE PE RAND

	lista_elemente();	///INITIALIZEAZA TOTUL CU 0, SI EVENTUAL CREEAZA UN ELEMENT NUL DE TIP VECT_DE_VECT
	lista_elemente(lst_vedeve);
	lista_elemente(lst_ve);
	lista_elemente(lst_mat);
	~lista_elemente();	///STERGE TOT-TOT DIN LISTA

};



lista_elemente::lista_elemente()
{
	p=(int*)NULL;
	nr_elemente=0;
}

lista_elemente::~lista_elemente()
{
	delete VECT_DE_VECT;
	nr_elemente=id=0;
	delete nxt;
	nxt=NULL;
}
