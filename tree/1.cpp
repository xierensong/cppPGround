
#include<bits/stdc++.h>

using namespace std;

typedef union error {int warning,err, excetpion;} ERROR;
enum fun{a,b=4,c,e=-5,f};
int main()
{
    ERROR e1={1};
    union error e2;
    e2.err=e1.warning;
    printf("%d", e2.warning);
    e2=e1;
    printf("%d",e2.excetpion);
    enum fun W,X,Y,Z;
    W=f;
    X=a;
    Y=c;
    Z=e;
    cout << X << ' ' << Z << ' ' << Y << ' ' << W << endl;
    printf("%d", X+Z-Y-W);
}