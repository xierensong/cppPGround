#include<bits/stdc++.h>

using namespace std;

void bob_sort(vector<int> &nums) 
{
    int len = nums.size();
    for(int i = len-1; i >= 0; --i) {
        for(int j = 0; j < i; ++j) {
            if (nums[j] > nums[j+1]) {
                int tmp = nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=tmp;
            }
        }
    }
}

int main()
{
    vector<int> nums{10,2,5,9,100,27,6};
    bob_sort(nums);
    for(auto num:nums) {
        cout <<num << ' ';
    }
    cout << endl;
    return 0;
}