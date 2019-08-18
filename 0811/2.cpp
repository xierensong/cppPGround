#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N=0,K=0;
    cin >> N >> K;
    string s;
    cin >> s;
    int len = N+K-1;
    string ss(N,'0');
    cout << ss << endl;
    if (N==1) ss=to_string(s[0]);
    for(int i = 0; i < K; i++) {
        if(i==0) {
            ss[i]=s[i];
            ss[N-1]=s[len-1];   //修改
        }
        else {
            ss[i]=(s[i]-'0')^(s[i-1]-'0') + '0';
            ss[N-i-1]=(s[len-i-1]-'0')^(s[len-i]-'0') + '0';
            //cout <<N-i-1 << ' ' << s[len-i-1] << ' ' << s[len-i] << ' ' << ss[N-i-1] << endl; //注释
        }
    }
    //新加
    for(int i = K; i <= N-1-K; i++) {
        ss[i]=(s[i-1]-'0')^(ss[i-K]-'0')^(s[i]-'0') + '0';
    }
    //新加
    cout << ss << endl;
    return 0;
}