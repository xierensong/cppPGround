#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int C = 0;
    cin >> C;
    while(C--) {
        int T = 0;
        cin >> T;
        vector<int> roles;
        int role = 0;
        for (int i = 0; i != T; i++) {
            cin >> role;
            if (role!=0) {
                roles.push_back(role);
            }
        }

        int len = roles.size();
        if (len < 3) {
            cout << 0 << endl;
        }
        else {
            sort(roles.begin(), roles.end());
            int count = 0;
            for(int i = 0; i <= len - 2; i++) {
                count += roles[i];
                roles[len-1] -= roles[i];
                roles[len-2] -= roles[i];
                roles.erase(roles.begin());
                len--;
                sort(roles.begin(), roles.end());
                for (int a : roles) {
                    cout << a << ' ';
                }
                i = -1;
                cout << count << endl;
            }
            cout << count << endl;
        }
    }


    return 0;
}