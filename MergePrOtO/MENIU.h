#include "VECT_DE_VECT.h"

void invalid()
{
    cout<<">> OPTIUNE INVALIDA. REINCERCATI <<\n";
}

void meniu ()
{
    cout<<"\n###########################################\n";
    cout<<"1.STOCARE 'N' OBIECTE\n";
    cout<<"2.OPERATII PE CLASA VECTOR\n";
    cout<<"3.OPERATII PE CLASA VECTOR DE VECTORI\n";
    cout<<"0. IESIRE PROGRAM\n";
    cout<<"###########################################\n";
    cout<<"OPTIUNE: ";
}

void op1 ()
{
    cout<<"\n1.STOCARE 'N' OBIECTE------------------------\n";
    cout<<"     1. CITIRE 'N' ELEMENTE DE LA TASTATURA\n";
    cout<<"     2. CITIRE 'N' ELEMENTE DINTR-UN FISIER\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";
}

void op2 ()
{
    cout<<"\n2.OPERATII PE CLASA VECTOR-----------------------\n";
    cout<<"     1. CITIRE VECTOR\n";
    cout<<"     2. AFISARE VECTOR\n";
    cout<<"     3. SUMA ELEMENTE VECTOR\n";
    cout<<"     4. AFISARE MAXIM VECTOR\n";
    cout<<"     0. REVENIRE\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";
}

void op22()
{
    cout<<"\n2.OPERATII PE CLASA VECTOR-----------------------\n";
    cout<<"     1. CITIRE ALT VECTOR\n";
    cout<<"     2. AFISARE VECTOR\n";
    cout<<"     3. SUMA ELEMENTE VECTOR\n";
    cout<<"     4. AFISARE MAXIM VECTOR\n";
    cout<<"     0. REVENIRE\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";
}

void op3 ()
{
    cout<<"\n3.OPERATII PE CLASA VECTOR DE VECTORI------------------\n";
    cout<<"     1. CITIRE VECTOR DE VECTORI\n";
    cout<<"     2. AFISARE VECTOR DE VECTORI\n";
    cout<<"     3. SUMA A DOI VECTORI DE VECTORI\n";
    cout<<"     4. CONVERSIE IN MATRICE A UNUI VECTORI DE VECTORI\n";
    cout<<"     0. IESIRE\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";

}

void op31 ()
{
    cout<<"\n3.1. CITIRE VECTOR DE VECTORI-----------------------\n";
    cout<<"     1. CITIRE DE LA TASTATURA\n";
    cout<<"     2. CITIRE DINTR-UN FISIER\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";
}

void op32 ()
{
    cout<<"\n3.2. AFISARE VECTOR DE VECTORI-------------------\n";
    cout<<"     1. AFISARE VECTORUL CITIT ADINEAURI\n";
    cout<<"     2. AFISARE UNUL DINTRE VECTORII CITITI LA OPTIUNEA '1'\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";
}

void op33()
{
    cout<<"\n3.3. SUMA A DOI VECTORI DE VECTORI-------------------\n";
    cout<<"     1. CITIRE VECTORI DE LA TASTATURA\n";
    cout<<"     2. ADUNARE DOI DINTRE VECTORII CITITI LA OPTIUNEA '1'\n";
    cout<<"-----------------------------------------------\n";
    cout<<"OPTIUNE: ";
}

void op34()
{
    cout<<"\n3.4. CONVERSIE IN MATRICE A UNUI VECTORI DE VECTORI\n----------\n";
    cout<<"     1. CONVERSIE VECTORUL CITIT ADINEAURI\n";
    cout<<"     2. CONVERSIE A UNUIA DINTRE VECTORII CITITI LA OPTIUNEA '1'\n";
    cout<<"--------------------------------------------------------------\n";
    cout<<"OPTIUNE: ";
}


void CAZ34(VECT_DE_VECT* p,int n,VECT_DE_VECT vee)
{int oopp;
op34();
cin>>oopp;

switch(oopp)
{
case 1:
    {
       if(vee.get_lin()==0) cout<<">NU S-A CITIT NICI UN VECTOR<\n";
       else
        {
            int** a;
            a=vee.creeaza_matrice();
            cout<<"MATRICEA CREATA ESTE: \n";
            for(int i=0;i<vee.get_lin();i++)
            {
                for(int j=0;j<vee.get_col();j++)
                    cout<<a[i][j]<<" ";
                cout<<"\n";
            }

            for(int i=0;i<vee.get_lin();i++) delete[] a[i];
            delete[] a;

        }
       break;
    }
case 2:
    {
        if(n)
        {int op;
            cout<<"AL CATELEA ELEMENT DORITI SA FIE CONVERTIT? (INTRE PRIMUL SI AL "<<n<<"-LEA\n";
            cin>>op;
            if(0<op && op<=n)
            {
                int** a;
            a=p[op].creeaza_matrice();
            cout<<"MATRICEA CREATA ESTE: \n";
            for(int i=0;i<p[op].get_lin();i++)
            {
                for(int j=0;j<p[op].get_col();j++)
                    cout<<a[i][j]<<" ";
                cout<<"\n";
            }

            for(int i=0;i<p[op].get_lin();i++) delete[] a[i];
            delete[] a;

            }
            else cout<<">CARDINAL INVALID<\n";
        }
        else cout<<">INCA NU S-AU CITIT NICI UN OBIECT<\n";
        break;
    }
default:
    {
        invalid();
        break;
    }
}
}

void CAZ33 (VECT_DE_VECT* p, int n)
{
int oopp;
op33();
cin>>oopp;


switch(oopp)
{
case 1:
    {
        VECT_DE_VECT v1,v2,v3;
        cout<<"~PRIMUL OBIECT~\n";
        cin>>v1;
        cout<<"~AL DOILEA OBIECT~\n";
        cin>>v2;
        v3=v1+v2;
       cout<<"SUMA CELOR DOI VECTORI DE VECTORI ESTE: \n"<<v3<<"\n";
       break;
    }
case 2:
    {
        if(n<2) cout<<">NU SUNT DESTULE OBIECTE MEMORATE LA OPTIUNEA '1'<\n";
        else
        {int a,b;
            cout<<"INTRODUCETI CARDINALELE CELOR DOI VECTORI PE CARE DORITI SA II ADUNATI : \n";
            cin>>a>>b;
            if((0<a&&a<=n)||(0<b&&b<=n)) cout<<">CARDINALE INVALIDE<\n";
            else
            {
                VECT_DE_VECT sum;
                sum=p[a-1]+p[b-1];
                cout<<"SUMA CELOR DOI VECTORI DE VECTORI ESTE: \n"<<sum<<"\n";
            }
        }
        break;
    }
default:
    {
        invalid();
        break;
    }
}

}

void CAZ32(VECT_DE_VECT* p,int n,VECT_DE_VECT vee)
{
op32();
int oopp;
cin>>oopp;

switch(oopp)
{
case 1:
    {
       if(vee.get_lin()==0) cout<<">NU S-A CITIT NICI UN VECTOR<\n";
       else cout<<"\nVECTORUL ESTE :\n"<<vee;
       break;
    }
case 2:
    {
        if(n)
        {int op;
            cout<<"AL CATELEA ELEMENT DORITI SA FIE AFISAT? (INTRE PRIMUL SI AL "<<n<<"-LEA\n";
            cin>>op;
            if(0<op && op<=n) cout<<p[op-1]<<"\n";
            else cout<<">CARDINAL INVALID<\n";
        }
        else cout<<">INCA NU S-AU CITIT 'N' OBIECTE<\n";
        break;
    }
default:
    {
        invalid();
        break;
    }
}

}

void CAZ31(VECT_DE_VECT& vee)
{
op31();
int oopp;
cin>>oopp;
switch(oopp)
{
case 1:
    {
        cin>>vee;
        break;
    }
case 2:
    {
        char a[30];
        cout<<"INTRODUCETI NUMELE FISIERULUI : ";
        cin>>a;
        ifstream f;
        f.open(a);
        if(f.is_open())
            {
                f>>vee;
                cout<<"OBIECT CITIT CU SUCCES\n";
                f.close();
            }
        else cout<<">NUME FISIER INVALID<\n";
        break;
    }
default:
    {
        invalid();
        break;
    }
}
}

void CAZ3(VECT_DE_VECT* p,int n)
{
int oopp;
VECT_DE_VECT vee;
op3();
cin>>oopp;
while(oopp!=0)
{

switch(oopp)
{
case 1:
    {
        CAZ31(vee);
        break;
    }
case 2:
    {
        CAZ32(p,n,vee);
        break;
    }
case 3:
    {
        CAZ33(p,n);
        break;
    }
case 4:
    {
        CAZ34(p,n,vee);
        break;
    }
case 0:
    {
        break;
    }
default:
    {
        invalid();
        break;
    }
}
op3();
cin>>oopp;
}

}

void CAZ2()
{
op2();
int opp;
VECTOR ve;
cin>>opp;
while(opp!=1)
{
    cout<<"NU S-A CITIT NICI UN VECTOR.";
    op2();
    cin>>opp;
}
cin>>ve;
while(opp!=0)
{
    op22();
    cin>>opp;
    switch(opp)
    {
    case 1:
        {
            cin>>ve;
            break;
        }
    case 2:
        {
            cout<<ve;
            break;
        }
    case 3:
        {
            cout<<"SUMA ELEMENTELOR VECTORULUI ESTE : "<<ve.suma_vct();
            break;
        }
    case 4:
        {
            cout<<"ELEMENTUL MAXIM AL VECTORULUI ESTE : "<<ve.get_elm_poz(ve.max_vect());
            break;
        }
    case 0:
        {
            break;
        }
    default:
        {
            invalid();
            break;
        }
    }

}
}

void CAZ1(VECT_DE_VECT*& p,int& n)
{
int opp;
op1();
cin>>opp;
switch(opp)
{
    case 1:
    {
    cout<<"NUMARUL DE OBIECTE: ";
    cin>>n;
    cout<<"\n";
    if(p!=NULL) delete[] p;
    p=new VECT_DE_VECT[n];
    for(int i=0;i<n;i++)
        {
        cout<<"OBIECTUL NUMARUL "<<i+1<<" :\n";
        cin>>p[i];
        cout<<"\n";
        }

    break;
    }
    case 2:
    {
    char a[30];
    cout<<"INTRODUCETI NUMELE FISIERULUI: ";
    cin>>a;
    ifstream f;
    f.open(a);
    if(f.is_open())
    {f>>n;
    if(p!=NULL) delete[] p;
    p=new VECT_DE_VECT[n];
    for(int i=0;i<n;i++)
        f>>p[i];

    cout<<"S-AU CITIT "<<n<<" OBIECTE DIN FISIERUL "<<a<<"\n";
    f.close();}
    else cout<<">NUME FISIER INVALID<\n";
    break;
    }
    default:{invalid();break;}
}
}
