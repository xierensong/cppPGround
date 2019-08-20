#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int n1[n],n2[n];
    for(int i = 0; i < n; i++)
        cin >> n1[i];
    for (int i = 0; i < n; i++)
        cin >> n2[i];
    int v1[n]={0};
    int v2[n]={0};
    vector<int> ans;
    for(int j = 0; j < n; j ++) {
        for(int k = m -1; k >= 0; k--) {
            if (v1[j]==0 && v2[k]==0 && n2[k]%m < (m-n1[j])) {
                v1[j]=1;
                v2[k]=1;
                ans.push_back((n1[j]+n2[k]) % m);
                continue;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = n-1; i >=0; i--)
        cout << ans[i] << ' ';
    cout << endl;
}