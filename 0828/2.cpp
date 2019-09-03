#include<bits/stdc++.h>

using namespace std;

int find (vector<int> & root, int i ) {
    while(root[i] != i) i = root[i];
    return i;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> persons;
    vector<int> langs;
    int tmp = k;
    vector<set<int>> lang_persons(m+1, set<int>{});
    
    while (tmp--)
    {
        int a,b;
        cin >> a >> b;
        lang_persons[a].insert(b);

    }
    vector<pair<int,int>> edges;

    for(int i = 1; !lang_persons[i].empty() && i <= m; i++) {
        for(int j = i+1; !lang_persons[j].empty() && j <= m; j++) {
            vector<int> res(min(lang_persons[i].size(), lang_persons[j].size()));
            auto iter = set_intersection(lang_persons[i].begin(), lang_persons[i].end(),
                                        lang_persons[j].begin(), lang_persons[j].end(),res.begin());
            if (iter - res.begin() > 0) {
                edges.push_back(make_pair(i,j));
            }
        }
    }

    int cnt = m;
    vector<int> root(m+1);
    for(int i = 1; i <= m; ++i) root[i] = i;
    for(auto a : edges) {
        int x = find (root, a.first),  y = find (root, a.second);
        if (x != y) {
            --cnt;
            root[y] = x;
        }
    }
    cout << cnt << endl;
    return 0;    
}