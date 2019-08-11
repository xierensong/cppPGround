#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int,int> my_dict;
    for(int i=0; i!=n; i++) {
        cin >> nums[i];
        my_dict[nums[i]]++;
    }
    int cnt=0;
    for(int i=0; i!=n; i++) {
        int target=nums[i];
        if(my_dict[target]==1) {
            my_dict.erase(target);
        }
        else {
            my_dict[target]--;
        }        
        for(int j=0; j!=n && j!=i; j++) {
            if(my_dict[nums[j]]==1) my_dict.erase(nums[j]);
            else my_dict[nums[j]]--;
            int left=target-nums[j];        
            for(auto p:my_dict) {
                cout << p.first << p.second << ' ';
            }
            cout << endl;
            if(my_dict.count(left)) {
                cnt++;
                cout << target << nums[j] << left << endl;
                break;
            }
            my_dict[nums[j]]++;
        }
        my_dict[target]++;
    }
    cout << cnt << endl;
    return 0;
}