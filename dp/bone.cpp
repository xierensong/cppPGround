/*
5 10
1 2 3 4 5  value
5 4 3 2 1  volume

14
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=5,m=10;
    vector<int> val{0,1,2,3,4,5};
    vector<int> vol{0,5,4,3,2,1};
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));//前i个骨头最大总体积j的最大价值
    dp[1][vol[1]]=val[1];
    
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if(j-vol[i]>=0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-vol[i]]+val[i]);
                //cout << dp[i][j] << endl;
            }
        }
    }
    for(auto v : dp) {
        for(auto a : v) {
            cout << a << '\t';
        }
        cout << endl;
    }
    cout << endl;
    cout << "max value: " << dp[n][m] << endl;
}