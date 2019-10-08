#include<bits/stdc++.h>

using namespace std;

void permute(int i, string &curr_str,vector<string> &results, string my_str)
{
    if(i == curr_str.size()-1) {
        results.push_back(curr_str);
    }
    else {
        for(int j=i; j < curr_str.size(); j++) {
            swap(curr_str[i], curr_str[j]);
            permute(i+1, curr_str, results, my_str);
            swap(curr_str[j],curr_str[i]);
        }
    }
}

int main()
{
    string my_str="abcd";
    vector<string> results;
    permute(0, my_str, results, my_str);
    for(auto result : results) {
        cout << result << ' ';
    }
    cout << results.size() << endl;
    cout << endl;
}