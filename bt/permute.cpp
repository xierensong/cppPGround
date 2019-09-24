#include<bits/stdc++.h>

using namespace std;

void permute(string str, int i, vector<string> &results) 
{
    if(i==str.size()-1) {
        results.push_back(str);
        return;
    }
    else {
        for(int j=i; j != str.size(); ++j) {
            char tmp=str[i];
            str[i]=str[j];
            str[j]=tmp;
            permute(str,i+1,results);
            tmp=str[j];
            str[j]=str[i];
            str[i]=tmp;
        }
    }
}

int main()
{
    string str="abc";
    vector<string> results;
    permute(str, 0, results);
    for(auto result : results) {
        cout << result << endl;
    }

}