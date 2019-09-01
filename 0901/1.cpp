#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> boxs;
    vector<long long> keys;
    int box_0 = 0, box_1 = 0, key_0 = 0, key_1 = 0;
    int tmp = n;
    while(tmp--) {
        long long curr;
        cin >> curr;
        if (curr % 2) {
            box_1++;
        }
        else {
            box_0++;
        }
    }
    tmp = m;
    while(tmp--) {
        long long curr;
        cin >> curr;
        if (curr % 2) {
            key_1++;
        }
        else {
            key_0++;
        }
    }
    cout << min(box_0, key_1) + min(box_1, key_0) << endl;
}