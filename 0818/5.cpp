#include<bits/stdc++.h>
#define max 110
#define INF 0x3f3f3f
int n,map1[max][max];//map记录两点间的最短路径 
 
using namespace std;

void dijkstra()
{
    int dis[max];//记录起始点到当前点的最短路径
	int visit[max];//标记是否訪问过了
    int i,j,next,min;
    memset(visit,0,sizeof(visit));
    for(i=1;i<=n;i++)
       dis[i]=map1[1][i];
    visit[1]=1;
    for(i=2;i<=n;++i)
    {
        min=INF;
        for(j=1;j<=n;++j)
        {
            if(visit[j]==0&&min>dis[j])
            {
                min=dis[j];
                next=j;
            }
        }
        visit[next]=1;
        for(j=1;j<=n;j++)
        {
            if(visit[j]==0&&dis[j]>dis[next]+map1[next][j])
                dis[j]=dis[next]+map1[next][j];
            cout << dis[j] << ' ';
        }
        cout << endl;
    }
    printf("%d\n",dis[n]);
}
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d", &n);
        memset(map1,INF,sizeof(map1));
        for(int i = 1; i != n+1; i ++) {
            for(int j = 1; j != n+1; j ++) {
                map1[i][j]=i ^ j; 
                map1[j][i]=i ^ j;
            }
        }
        dijkstra();
    }    
    return 0;
}