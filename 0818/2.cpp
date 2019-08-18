#include<bits/stdc++.h>

using namespace std;

bool func(vector<int> &res, int i, string out_str, unordered_multimap<char,int> in_dict, int M) {
    if (res.size() == M) {
        return true;
    }
    for (int j = i; j != out_str.size(); j++) {
        char key = out_str[j];
        auto low_up = in_dict.equal_range(key);
        if (low_up . first == low_up . second) {
            res.push_back(j);
        }
        else {
            //排序
            vector<int> cands;
            for(auto it = low_up . first; it != low_up . second; it++) {
                cands.push_back(it -> second);
            }
            sort(cands.begin(), cands.end());
            for(auto it = cands.begin(); it != cands.end(); it++) {
                res.push_back(*it);
                bool ret = func(res, i+1, out_str, in_dict, M);
                if (ret) {
                    return true;
                }
                else {
                    res.pop_back(*it);
                }
            }
        }
    }
    return false;
}

main()
{
    int T=0;
    scanf("%d", &T);
    while(T--) {
        int N,M;
        scanf("%d%d",&N, &M);
        vector<int> result;
        unordered_multimap<char,int> in_dict, out_dict;
        while(N--) {
            string in_str;
            cin >> in_str;
            for(int i = 0; i != in_str.size(); i++) {
                in_dict.insert(make_pair(in_str[i], i));
            }
            string out_str;
            cin >> out_str;
            vector<int> curr_res;
            


            for(int i = 0; i != out_str.size(); i++) {
                out_dict.insert(make_pair(out_str[i], i));
            }
            for(auto it = in_dict.begin(); it != in_dict.end(); ++it) {
                char key = it -> first;
                auto low_up = in_dict.equal_range(key);
                auto low_up_1 = out_dict.equal_range(key);
                for(vector<int>::iterator idx_it = low_up.first, vector<int>::iterator idx_it_1 = low_up_1.first; 
                    idx_it != low_up.second, idx_it_1 != low_up_1.second; 
                    idx_it++, idx_it_1++) {
                    cout << (*idx_it).first << ' ' << (*idx_it).second  << '\t'
                            idx_it_1 -> first << ' ' << idx_it_1 -> second<< endl;
                }
           
                cout << endl;                 
            }
        }
    }
}