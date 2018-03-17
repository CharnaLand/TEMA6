#include <iostream>
#include <fstream>
#include "VECTOR.h"

using namespace std;

class VECT_DE_VECT
{

int nr_linii, nr_coloane;
VECTOR* vedeve;

public:
    int** creeaza_matrice ();
    void umple_zero();              ///DEJABA !
    void afis_drept_matrice();
    ///GET
    int get_lin () {return nr_linii;}
    int get_col () {return nr_coloane;}
    int get_elm_matr(int i,int j) {return vedeve[i].get_elm_poz(j);}
    ///CONSTRUCTORI
    VECT_DE_VECT();
//    VECT_DE_VECT(int,int);///MATRICE PATRATICA. CAT PE CAT. NEEEEE
    VECT_DE_VECT(VECT_DE_VECT&); ///COPIERE
    ///DESTRUCTOR
    ~VECT_DE_VECT();
    ///SUPRAINCARCARI
    VECT_DE_VECT& operator+ (VECT_DE_VECT&);///?
    VECT_DE_VECT& operator= (VECT_DE_VECT&);
//    VECT_DE_VECT& operator- (VECT_DE_VECT&);    ///OPTIONAL..
//    VECT_DE_VECT& operator* (VECT_DE_VECT&);    ///SI MAI OPTIONAL!!
    ///FRIENDS
    friend ifstream& operator>> (ifstream&,VECT_DE_VECT&);
    friend istream& operator>> (istream&,VECT_DE_VECT&);
    friend ostream& operator<< (ostream&,VECT_DE_VECT&);
friend class VECTOR;
};

ifstream& operator>> (ifstream& fin, VECT_DE_VECT& vv)
{int x;
    fin>>vv.nr_linii;
    vv.nr_coloane=0;
    vv.vedeve=new VECTOR[vv.nr_linii];
    for(int i=0;i<vv.nr_linii;i++)
    {
        fin>>x;
        vv.nr_coloane=max(x,vv.nr_coloane);
        vv.vedeve[i].set_elm(x);
    }///SETEAZA TOATE LUNGIMILE LINIILOR DE TIP VECTOR

    for(int i=0;i<vv.nr_linii;i++)
    {
        int n=vv.vedeve[i].get_elm();
        int* p=new int[n];
        for(int j=0;j<n;j++) fin>>p[j];
        vv.vedeve[i].set_vct(p);
    }
return fin;
}

ostream& operator<< (ostream& out,VECT_DE_VECT& vv)///FARA 0 LA SFARSIT
{
    for(int i=0;i<vv.nr_linii;i++)
    {
        int k=vv.vedeve[i].get_elm();

        for(int j=0;j<k;j++)
            out<<vv.vedeve[i].get_elm_poz(j)<<" ";
        out<<"\n";
    }
return out;
}

VECT_DE_VECT::VECT_DE_VECT()
{
nr_coloane=0;
nr_linii=0;
vedeve=NULL;
}

VECT_DE_VECT::VECT_DE_VECT(VECT_DE_VECT& vv)
{
    nr_coloane=vv.nr_coloane;
    nr_linii=vv.nr_linii;

    vedeve=new VECTOR[nr_linii];
    for(int i=0;i<nr_linii;i++)
    {
        int n=vv.vedeve[i].get_elm();
        vedeve[i].set_elm(vv.vedeve[i].get_elm());

        int *p=new int[n];
        for(int j=0;j<n;j++) p[j]=vv.vedeve[i].get_elm_poz(j);
        vedeve[i].set_vct(p);
    }
}

/**
VECT_DE_VECT::VECT_DE_VECT(int CAT_PE_CAT, int CE)
{
    nr_coloane=nr_linii=CAT_PE_CAT;
    vedeve=new VECTOR[CAT_PE_CAT];
    for(int i=0;i<CAT_PE_CAT;i++)
    {
        vedeve[i].set_elm(CAT_PE_CAT);
        int* p=new int[CAT_PE_CAT];
        for(int j=0;j<CAT_PE_CAT;j++)
            p[i]=CE;
        vedeve[i].set_vct(p);
    }
}
*/


VECT_DE_VECT::~VECT_DE_VECT()
{
    delete[] vedeve;
    vedeve=NULL;
    nr_coloane=nr_linii=0;
}

void dezaloc_matr (int** v,int linii)
{
for(int i=0;i<linii;i++)
    delete[] v[i];
delete[] v;
}

int** VECT_DE_VECT::creeaza_matrice()
{
    int** a=new int*[nr_linii];
    for(int i=0;i<nr_linii;i++)
        a[i]=new int[nr_coloane];

    for(int i=0;i<nr_linii;i++)
    {
        int k=vedeve[i].get_elm();
        for(int j=0;j<k;j++) a[i][j]=vedeve[i].get_elm_poz(j);

        for(int j=k;j<nr_coloane;j++) a[i][j]=0;
    }

return a;
}

void VECT_DE_VECT::umple_zero()
{
    for(int i=0;i<nr_linii;i++)
    {
        int k=vedeve[i].get_elm();
        int* p=new int[nr_coloane];
        for(int j=0;j<k;j++) p[j]=vedeve[i].get_elm_poz(j);
        for(int j=k;j<nr_coloane;j++) p[j]=0;
        vedeve[i].schimba_vct(p);
        vedeve[i].set_elm(nr_coloane);
    }

}

VECT_DE_VECT& VECT_DE_VECT::operator+(VECT_DE_VECT& vv)
{
VECT_DE_VECT* sum=new VECT_DE_VECT;
int lin=max(nr_linii,vv.nr_linii), col=max(nr_coloane,vv.nr_coloane);
sum->nr_linii=lin;
sum->nr_coloane=col;
sum->vedeve=new VECTOR[lin];
for(int i=0;i<lin;i++)
{
    sum->vedeve[i].set_elm(col);                            ///CE AM IN COMUN
    int c=min(vedeve[i].get_elm(),vv.vedeve[i].get_elm());
    int C=max(vedeve[i].get_elm(),vv.vedeve[i].get_elm());
    int *p=new int[col];
    for(int j=0;j<c;j++) p[i]=vedeve[i].get_elm_poz(j)+vv.vedeve[i].get_elm_poz(j);

    if(vedeve[i].get_elm()>vv.vedeve[i].get_elm())          ///CE ARE DOAR O COLOANA
        for(int j=c;j<C;j++) p[i]=vedeve[i].get_elm_poz(j);
    else
        for(int j=c;j<C;j++) p[i]=vvvedeve[i].get_elm_poz(j);

    for()                                                   ///ZEROURI LA COLOANELE MAI SCURTE
}
    ///DE AICI BAGI NUMAI 0

return *sum;
}

int main()
{
VECT_DE_VECT v1;
ifstream f ("date.in");
f>>v1;
cout<<v1;
VECT_DE_VECT v2(v1);
cout<<"\n"<<v2;
f.close();

int** c;
c=v2.creeaza_matrice();
cout<<"\n";
for(int i=0;i<v2.get_lin();i++)
{
    for(int j=0;j<v2.get_col();j++)
        cout<<c[i][j]<<" ";
cout<<"\n";
}
v1.umple_zero();
cout<<v1;

return 0;
}
