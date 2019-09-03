#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    vector<int> nums={1,2,3,4,5,11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45};
    while(true) {
        cin >> a >> b >> c >> d >> e >> f;
        vector<int> my_list={a,b,c,d,e,f};
        sort(my_list.begin(), my_list.end());
        set<int> cands;
        a=my_list[0];
        auto it = find(nums.begin(), nums.end(), a);
        if (it == nums.end()) {  //没找到
            printf("%d",0);
            continue;
        }
        else
        {
            int idx = it - nums.begin();
            if ((idx + 1) % 6 <= 5 && (idx + 1) % 6 >= 1)
            {
                cands.insert(idx + 1);
            }
            if (idx >= 1 && (idx - 1) % 6 <= 4 && (idx - 1) % 6 >= 0)
            {
                cands.insert(idx - 1);
            }
            if ((idx + 6) % 6 <= 5 && (idx + 6) % 6 >= 0)
            {
                cands.insert(idx + 6);
            }
            if (idx >= 6 && (idx - 6) % 6 <= 5 && (idx - 6) % 6 >= 0)
            {
                cands.insert(idx - 6);
            }
            /*
            for(auto a : cands) {
                cout << a << ' ';
            }            
            cout << endl;*/
            int flag = 0;
            for (int i = 1; i != 6; i++)
            {
                //cout << "curr " << my_list[i] << endl;
                auto it = find(nums.begin(), nums.end(), my_list[i]);
                if (it == nums.end())
                { //没找到
                    //cout << "没找到" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    int idx = it - nums.begin();
                    //cout << "idx " << idx << endl;
                    if (cands.count(idx) == 0)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        cands.erase(idx);
                        if ((idx + 1) % 6 <= 5 && (idx + 1) % 6 >= 1)
                        {
                            cands.insert(idx + 1);
                        }
                        if ((idx - 1) % 6 <= 4 && (idx + 1) % 6 >= 0)
                        {
                            cands.insert(idx - 1);
                        }
                        if ((idx + 6) % 6 <= 5 && (idx + 6) % 6 >= 1)
                        {
                            cands.insert(idx + 6);
                        }
                        if ((idx - 6) % 6 <= 4 && (idx - 6) % 6 >= 0)
                        {
                            cands.insert(idx - 6);
                        }
                    }
                }
            }
            if (flag == 1) {
                printf("%d",0);
            }
            else {
                printf("%d",1);
            }
        }
    }


}