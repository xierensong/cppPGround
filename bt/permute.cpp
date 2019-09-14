#include<bits/stdc++.h>

using namespace std;

void permute(string &my_str, int i, vector<string> &results)
{
    //cout << "i " << i << endl;
    if(i==my_str.size()-1) {
        results.push_back(my_str);
    }
    else {
        for(int j = i; j < my_str.size(); j++) {
            swap(my_str[i], my_str[j]);
            permute(my_str, i+1, results);
            swap(my_str[i], my_str[j]);
        }
    }
}

int main()
{
    string my_str="abcdef";
    vector<string> results;
    permute(my_str, 0, results);

    for(auto result:results) {
        cout << result << endl;
    }
    cout << endl;
        cout << results.size() << endl;
}