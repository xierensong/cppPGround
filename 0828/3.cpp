#include<bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int k;
    cin >> line >> k;
    vector<pair<int,int>> boys;
    for(int i = 0; i != line.size(); ++i) {
        if (line[i] == 'g') {
            int girl_cnt = 0;
            int j = (i+1) % line.size();
            //cout << line.size() << ' ' << j << ' ' << line[j] << endl;
            while(line[j] == 'b') {
                girl_cnt++;
                j++;
            }
            boys.push_back(make_pair(i, girl_cnt));
        }
    }
    /*
    for(auto p : boys) {
        cout << p.first << ' ' << p.second << endl;
    }*/
    int boy_cnt = boys.size();
    if (boy_cnt <= k) {
        int boy_sum = 0;
        for(int i = 0; i != boys.size(); i++) {
            boy_sum += boys[i].second;
        }
        cout << boy_sum << endl;
    }
    else {
        int boy_sum = 0, curr_sum = 0;
        for(int i = 0; i <= k; i++) {
            boy_sum += boys[i].second;
        }
        curr_sum = boy_sum;
        //cout << boy_sum << endl;
        for(int i = 1; i < boys.size(); i++) {
            //cout << curr_sum << ' ' << (i+3)%boys.size() << ' ' << boys[(i+3)%boys.size()].second << ' ' << boys[i-1].second << endl;
            curr_sum = curr_sum + boys[(i+3)%boys.size()].second - boys[i-1].second;
            //cout << curr_sum << endl;
            if (curr_sum > boy_sum) {
                boy_sum = curr_sum;
            }
        }
        cout << boy_sum << endl;
    }
}