#include<bits/stdc++.h>

using namespace std;

int main()
{
    string A;
    string B;
    cin >> A >> B;
    int cnt = 0;
    int len1 = A.size();
    int len2 = B.size();
    for(int i = 0; i <= len1 - len2; ++i) {
        int k = i, j = 0;
        bool match=true;
        while(j < len2) {
            if(A[k]!=B[j]) {
                match=false;
                break;
            } 
            k++;
            j++;
        }
        if(match) {
            cout << "match " << i << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
}