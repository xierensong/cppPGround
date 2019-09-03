#include<bits/stdc++.h>

using namespace std;

int fun1(int i) {
    return i <= 5?i:fun1(i-1)*fun1(i-3);
}

int fun2(unsigned int i) {
    return ((i >>8) & 0x6597) & (((i << 8)& 0x6597) >> 8);
}

int main()
{
    int n=fun2(fun1(101))%4;
    printf("%d",n);
    return 0;
}