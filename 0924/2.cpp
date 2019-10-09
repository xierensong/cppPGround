#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    long long a, b;
    cin >> a >> b >> n;
    long  long carry=(a*b)/10;
    long long val=(a*b)%10;
    long long res=val;
    //cout << val << '\t' << carry << endl;
    int curr_carry = carry;
    while(--n) {
        int cur=(val+curr_carry) % 10;
        curr_carry=carry + (val+curr_carry) / 10;
        //cout << cur << '\t' << curr_carry << endl;
        res+=cur;
    }
    cout << res + curr_carry << endl;
}