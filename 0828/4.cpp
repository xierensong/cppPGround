#include<bits/stdc++.h>

using namespace std;

int main()
{
    string my_str;
    cin >> my_str;
    int len = my_str.size();
    if (len<=1) {
        cout << len << endl;
    }
    int max_cnt = 0;
    for(int i = 1; i != len; i++) { //不同长度
        int curr_cnt = 0;   //当前长度数量
        for(int j = 0; j <= len - i; j++) { //当前子串
            string target_sub = my_str.substr(j, i);
            cout << "target_sub " << target_sub << endl;
            for(int k = j + 1; k <= len - i; k++) { //
                string cur_sub = my_str.substr(k, i);
                cout << "cur_sub " << cur_sub << endl;
                if (target_sub == cur_sub) {
                    curr_cnt ++;
                    cout << "add 1" << endl;
                }
            }
            max_cnt = max(max_cnt, curr_cnt);
        }
    }
    cout << max_cnt << endl;
}