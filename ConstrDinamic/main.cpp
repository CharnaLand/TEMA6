#include <iostream>

using namespace std;

class Vector
{
    int nr_elem;
    int *v;
public:
    friend class Vectori_de_vectori;
    Vector();
    Vector(int, int);
    Vector(int nr);
    Vector(const Vector&);
    ~Vector();
    void afisare();
    void actualizare(int, int);
    void operator=(const Vector);
    friend istream& operator>> (istream&, Vector&);
    friend ostream& operator<< (ostream&, Vector&);

};

class Vectori_de_vectori
{
    int dim;
    Vector *V;
public:
    Vectori_de_vectori(int x=0, int d=0);
    ~Vectori_de_vectori();
    Vectori_de_vectori(const Vectori_de_vectori&);
    friend istream& operator>>(istream&, Vectori_de_vectori&);
    void citire();
    void afisare();
    void dezaloca_v(int,Vectori_de_vectori& );
};

void Vectori_de_vectori::dezaloca_v(int i, Vectori_de_vectori& a)
{
    delete a.V[i].v;
}

istream& operator>>(istream& in, Vectori_de_vectori& a)
{
    for(int i=0;i<a.dim;i++)
    a.dezaloca_v(i,a);
    cout<<"Numarul de vectori este ";
    in>>a.dim;
    int i;

    for(i=0;i<a.dim;i++)
        cin>>a.V[i];

    return in;

}

Vectori_de_vectori::Vectori_de_vectori(const Vectori_de_vectori& b)
{
    int i;
    dim=b.dim;
    V=new Vector [dim];
    for(i=0;i<dim;i++)
        V[i]=b.V[i];
}

void Vectori_de_vectori::afisare()
{
    int i;
    for(i=0;i<dim;i++)
        cout<<V[i];
}

void Vectori_de_vectori::citire()
{
   cout<<"Numarul de vectori ";
    cin>>dim;
    int i;
    for(i=0;i<this->dim;i++)
        cin>>V[i];
}

Vectori_de_vectori::~Vectori_de_vectori()
{
    for(int i=0;i<this->dim;i++)
        V[i].~Vector();
    delete V;

}

Vector::Vector()
{
    nr_elem=0;
    v=NULL;
}

Vectori_de_vectori::Vectori_de_vectori(int x, int d)
{ if(d==0)
 { dim=0;
   V=new Vector[1];
  this->V[0].nr_elem=1;
  V[0].v=new int[V[0].nr_elem];
  this->V[0].v[0]=0;
  }
 else
    {
    dim=d;
    V=new Vector[dim];

    for(int i=0;i<dim;i++)
    {   delete[] V[i].v;
        cout<<"Nr_elem= ";
        cin>>V[i].nr_elem;
        V[i].v=new int [V[i].nr_elem];
        for(int j=0;j<V[i].nr_elem;j++)
           V[i].v[j]=x;
           }}
}

ostream& operator<<(ostream& out, Vector&a)
{
    int i;
    for(int i=0;i<a.nr_elem;i++)
        out<<a.v[i]<<" ";
    out<<endl;
    return out;
}

istream& operator>>(istream& in, Vector& a)
{
    int nr;
    cout<<"Numarul de coloane este ";
    in>>nr;
    delete[] a.v;
    a.nr_elem=nr;
    a.v=new int [a.nr_elem];
    for(int i=0;i<a.nr_elem;i++)
      {  cout<<"Elementul este: "; in>>a.v[i];}
    return in;
}

void Vector::afisare()
{
    int i;
    for(i=0;i<nr_elem;i++) cout<<v[i]<<" ";
}

void Vector::actualizare(int x, int nr)
{
    delete[] v;
    nr_elem=nr;
    v=new int [nr];
    int i;
    for(i=0;i<nr;i++)
        v[i]=x;
}

void Vector::operator=(const Vector a)
{
    delete[] v;
    this->nr_elem=a.nr_elem;
    v=new int [nr_elem];
    int i;
    for(i=0;i<nr_elem;i++) v[i]=a.v[i];
}

Vector::~Vector()
{
    delete[] v;
    nr_elem=0;
}

Vector::Vector(int nr)
{
    nr_elem=nr;
    v=new int[this->nr_elem];
}

Vector::Vector(const Vector& cop)
{
    v=new int[cop.nr_elem];
    nr_elem=cop.nr_elem;
    int i;
    for(i=0;i<nr_elem;i++)
        v[i]=cop.v[i];
}

Vector::Vector(int x,int nr)
{
    this->nr_elem=nr;
    v=new int[nr];
    for(int i=0;i<nr;i++)
        v[i]=x;
}

int main()
{
    Vectori_de_vectori a;

    cin>>a;
    a.afisare();
   // Vectori_de_vectori c(a);
   // c.afisare();
    return 0;
}
