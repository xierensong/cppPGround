#include<bits/stdc++.h>

using namespace std;

long long func(long long f_1, long long f_2, long long f_3, int a, int b, int c, int i) {
    long long ans = 0;
    ans +=  (a * f_1) % 1000000007;
    ans %= 1000000007;
    ans += (b * f_2) % 1000000007;;
    ans %= 1000000007;
    ans += (c * f_3) % 1000000007;
    ans %= 1000000007;
    ans += (2 * i * i - i + 32767) % 1000000007;   
    return ans % 1000000007;
}

main()
{
    long long n = 0;
    long long a = 0, b = 0, c = 0;
    long long f[4] = {0};
    cin >> n >> a >> b >> c >> f[0];
    long long i = 0;
    while(i <= n) {
        if (i % 4 == 0) {
            f[0] = func(f[3],f[2], f[1], a, b, c, i);
            //cout << f[0] << endl;
        }
        else if (i % 3 == 1) {
            f[1] = func(f[0], f[3], f[2], a, b, c, i);
            //cout << f[1] << endl;
        }
        else if (i % 3 == 2) {
            f[2] = func(f[1], f[0], f[3], a, b, c, i);
            //cout << f[2] << endl;
        }
        else {
            f[3] = func(f[2], f[1], f[0], a, b, c, i);
            //cout << f[3] << endl;
        }
        i++;
    } 
    cout << f[(i-2) % 4] << endl;
    return 0;

}