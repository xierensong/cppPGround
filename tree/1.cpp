#include<bits/stdc++.h>

using namespace std;

bool preOrder(vector<vector<int>> Tree, int root, int &cnt) {
    //cout << "root " << root << ' ' << "cnt " << cnt << endl;

        vector<int> idxs;
        for(int i = 0; i<=Tree[1].size();i++) {
            if (Tree[1][i] == root) {
                idxs.push_back(i);
                //cout << "i " << i << endl;
            }
        }

        if (idxs.size()==0) {
            for(int i = 0; i<=Tree[0].size();i++) {
                if (Tree[0][i] == root) {
                    cnt++;
                    return true;
                    //cout << "i " << i << endl;
                }
            }        
        }
        else {
            cnt++;
        for(int i = 0; i != idxs.size(); i++) {
            int child = Tree[0][idxs[i]];
            //cout << "child " << child << endl;
            if(preOrder(Tree,child, cnt)) {
                return true;
            }
        }
        }
    return false;
}

int main()
{
    vector<vector<int>> Tree(2, vector<int>());
    string line;
    getline(cin,line);
    stringstream ss1(line);
    int a;
    while(ss1 >> a) {
        Tree[0].push_back(a);
    }
    line="";
    getline(cin,line);
    stringstream ss2(line);
    while(ss2 >> a) {
        Tree[1].push_back(a);
    }
    //cout << Tree[0][0] << ' ' << Tree[1][0] << endl;   
    cin >> a;
    int cnt = 0;
    preOrder(Tree,a, cnt);
    cout << cnt << endl;
}