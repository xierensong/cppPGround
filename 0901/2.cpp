#include<bits/stdc++.h>

using namespace std;
float ConvertStringToFloat(string str)
{
    int len = str.size();
    if (len == 0) return 0;
    if (str[0] <= '0' || str[0] > '9') {
        return 0;
    }
    int curr = str[0]-'0';
    float left = 1.0 * curr; 
    int i = 1;
    for(i = 1; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            left = left* 10 + str[i] -'0';
        }
        else if (str[i] == '.') {
            break;
        }
    }
    float right = 0.0;
    if (i < len-1) {
        right = 0.0;
        for(int j = len-1; j > i; --j) {
            if (str[j] >= '0' && str[j] <= '9') {
                right = right*0.1  + (str[j] -'0') *0.1;
                cout << "right " << right << endl;
            }
        }
    }
    float res = left + right;
    return res;
}

int main()
{
    string my_str;
    cin >> my_str;
    float res = ConvertStringToFloat(my_str);
    cout << res << endl;
}