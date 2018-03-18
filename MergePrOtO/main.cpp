#include <iostream>
#include <fstream>
#include "MENIU.h"

using namespace std;

int main()
{

int op,n=0;
VECT_DE_VECT* p=NULL;
meniu();
cin>>op;
while(op!=0)
{
    switch(op)
    {
    case 1:
        {
            CAZ1(p,n);
            break;
        }
    case 2:
        {
            CAZ2();
            break;
        }
    case 3:
        {
            CAZ3(p,n);
            break;
        }
    case 0:{break;}
    default: {invalid();break;}
    }
meniu();
cin>>op;
}



return 0;
}
