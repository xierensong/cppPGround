#include<bits/stdc++.h>

using namespace std;

int p[11];
int findset(int x) {
    return  p[x]==x?x:p[x]=findset(p[x]);
}

int main()
{
    int n, pair, u, v;
    scanf("%d %d", &n, &pair);
    for(int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for(int i = 1; i <= pair; ++i) {
        scanf("%d %d", &u, &v);
        p[findset(u)]=findset(v);
    }
    int tot=0;
    for(int i =1;i <= n; ++i) {
        tot += (p[i]==i);
    }
    cout << tot << endl;
    return 0;
}