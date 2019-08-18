#include<bits/stdc++.h>

using namespace std;

long long calc_sum(long long V)
{
    long long ans = 0;
    while(V / 10 != 0 || V % 10 != 0)
    {
        ans += V % 10;
        V = V / 10;
    }
    return ans;
}
int main()
{
    int T=0;
    cin >> T;
    while(T--) 
    {
        long long V = 0;
        cin >> V;
        long long digit_sum = calc_sum(V);
        //cout << digit_sum << endl;
        //计算因子
        vector<long long> res;
        for (long long i = 1; i <= digit_sum; i ++) {
            if ((digit_sum % i == 0 ) && (V % i == 0)) {
                res.push_back(i);
            }
        }
        printf("%lld\n", (long long) res.size());
        for (long long a : res) {
            printf("%lld ", a);
        }
        printf("\n");
    }
    return 0;
}