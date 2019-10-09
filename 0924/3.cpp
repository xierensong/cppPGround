#include<bits/stdc++.h>

using namespace std;

void func(vector<vector<char>> &plane, int x, int y, int direction, int N, int M, int &cnt) {
    //cout << x << '\t' << y << '\t' << plane[x][y] << '\t' << direction << '\t' << cnt << endl;
    if(x >N || x <= 0 || y >M || y <= 0) {
        return;
    }
    if(plane[x][y]=='N') {
        plane[x][y]=' ';
        x--;
        direction=0;
    }
    else if(plane[x][y]=='S') {
        plane[x][y]=' ';
        x++;
        direction=2;
    }
    else if (plane[x][y]=='W') {
        plane[x][y]=' ';
        y--;
        direction=3;
    }
    else if (plane[x][y]=='E') {
        plane[x][y]=' ';
        y++;
        direction=1;
    }
    else if (plane[x][y]==' ') {
        if (direction==0) {
            x--;
        }
        else if (direction==1) {
            y++;
        }
        else if (direction==2) {
            x++;
        }
        else if (direction==3) {
            y--;
        }
        
    }
    cnt++;
    func(plane, x, y, direction, N, M, cnt);
    return;
}

int main()
{
    int N,M;
    cin >> N >> M;
    vector<vector<char>> plane(N+1, vector<char>(M+1,' '));
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            char a;
            cin >> a;
            plane[i][j]=a;
        }
    }
    int x, y;
    cin >> x >> y;
    int cnt=0;
    func(plane, x, y, -1, N, M, cnt);
    cout << cnt << endl;
}