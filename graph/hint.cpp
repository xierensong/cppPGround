#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> res;
    string my_line;
    getline(cin, my_line);
    stringstream ss(my_line);
    string word;
    while(ss >> word) {
        res.push_back(word);
    }
    for(auto word : res) {
        cout << word << ' ';
    }
    cout << endl;
}