#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> w(N);
    vector<int> v(N);
    for(int i = 0; i!=N; i++) {
        cin >> w[i];
    }
    for(int i = 0; i != N; i++) {
        cin >> v[i];
    }
    vector<int> dp(M+1,0);
    for(int i = 0; i < N; i++) {
        for(int j = M; j >=w[i]; j--) {
            dp[j]=max(dp[j], dp[j-w[i]]+v[i]);

        }

    }
    cout << dp[M-1] << endl;
    return 0;
}