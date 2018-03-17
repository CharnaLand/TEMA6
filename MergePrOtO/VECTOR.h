#include <iostream>
#include <fstream>

using namespace std;

class VECTOR
{
    int elm;
    int* vct;
public:
    VECTOR& operator+ (VECTOR&);
    VECTOR& operator= (VECTOR&);
    //VECTOR*& operator= (VECTOR*&);
    ///GET
    int get_elm_poz(int);
    int get_elm(){return elm;}
    ///SET
    void set_elm(int x){elm=x;}
    void set_vct (int* p){vct=p;}
    ///CONSTRUCTORI
    VECTOR();
    VECTOR(int,int);
    VECTOR(VECTOR&);
    ///DESTRUCTOR
    ~VECTOR();
    ///ALTELE
    void afis_vect ();
    void reactualizare(int,int);
    void schimba_vct(int* p) {delete vct; vct=p;}
    int suma_vct();
    int max_vect();
    ///STREAM
    friend ifstream& operator>> (ifstream& in,VECTOR& ve);
    friend istream& operator>> (istream& in,VECTOR& ve);
    friend ostream& operator<< (ostream& out,VECTOR& ve);

friend class VECT_DE_VECT;  ///GRIJA LA REDENUMIRE
};

ifstream& operator>> (ifstream& in,VECTOR& ve)
{
    in>>ve.elm;
    delete[] ve.vct;
    ve.vct=new int[ve.elm];
    for(int i=0;i<ve.elm;i++)
        in>>ve.vct[i];
    return in;
}

istream& operator>> (istream& in,VECTOR& ve)
{
    in>>ve.elm;
    delete[] ve.vct;
    ve.vct=new int[ve.elm];
    for(int i=0;i<ve.elm;i++)
        in>>ve.vct[i];
    return in;
}


ostream& operator<< (ostream& out,VECTOR& ve)
{
    for(int i=0;i<ve.get_elm();i++)
        out<<ve.get_elm_poz(i)<<" ";
    out<<"\n";
    return out;
}

VECTOR::VECTOR()
{
    elm=0;
    vct=NULL;
};

VECTOR::VECTOR(int cate, int ce)
{
    vct=new int[cate];
    for(int i=0;i<cate;i++)
        vct[i]=ce;
    elm=cate;
}

VECTOR::VECTOR(VECTOR& v)
{
    elm=v.elm;
    int* p=new int[elm];
    for(int i=0;i<elm;i++)
        p[i]=v.vct[i];
    vct=p;

};

VECTOR::~VECTOR()
{
if(elm!=0) delete[] vct;
elm=0;
vct=NULL;
}

VECTOR& VECTOR:: operator= (VECTOR& v)
{
    elm=v.elm;
    vct=new int[elm];
    for(int i=0;i<elm;i++)
        vct[i]=v.vct[i];
return *this;
}

VECTOR& VECTOR::operator+ (VECTOR& v)
{
    VECTOR *sum;
    sum=new VECTOR;
    sum->elm=max(elm,v.elm);
    sum->vct=new int[sum->elm];
    int n=min(elm,v.elm),M=max(elm,v.elm);
    for(int i=0;i<n;i++)
        sum->vct[i]=vct[i]+v.vct[i];
    if(v.elm>elm)
        for(int i=n;i<M;i++) sum->vct[i]=v.vct[i];
    if(v.elm<elm)
        for(int i=n;i<M;i++) sum->vct[i]=vct[i];

    return *sum;
}

void VECTOR::afis_vect()
{
if(elm!=0)
{
for(int i=0;i<elm;i++)
    cout<<vct[i]<<" ";
cout<<"\n";
}
}

void VECTOR::reactualizare(int ce,int cate)
{
elm=cate;
delete[] vct;
vct=new int[cate];
for(int i=0;i<cate;i++)
    vct[i]=ce;
}

int VECTOR::suma_vct()
{
int sum=0;
for(int i=0;i<elm;i++)
    sum+=vct[i];
return sum;
}

int VECTOR::get_elm_poz(int i)
{
    if(elm!=0 && i<elm && i>=0) return vct[i];
    else return -1;
}

int VECTOR::max_vect()
{
int mx=INT_MIN, p=-1;
for(int i=0;i<elm;i++)
    if(vct[i]>mx)
    {
        mx=vct[i];
        p=i;
    }
return p;
}
