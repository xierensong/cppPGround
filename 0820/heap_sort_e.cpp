#include<bits/stdc++.h>

using namespace std;

void adjust(vector<int> &nums, int s, int t) 
{
    int num = nums[s];
    for(int i = s * 2 + 1; i <= t; ++i) {
        if (i < t && nums[i] < nums[i+1]) i++;
        if (num < nums[i]) {
            nums[s]=nums[i];
            s = i;
        }
    }
    nums[s]=num;
}

void heap_sort(vector<int> &nums) 
{
    //建堆
    int len = nums.size();
    for(int i = len / 2 - 1; i >=0; --i) {
        adjust(nums, i, len-1);
    }
    //输出堆
    for(int i = len-1; i >= 0; --i) {
        int tmp=nums[0];
        nums[0]=nums[i];
        nums[i]=tmp;
        adjust(nums, 0, i-1);
    }
}


int main()
{
    vector<int> nums{2,3,8,5,18,1,21,7};
    heap_sort(nums);
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}