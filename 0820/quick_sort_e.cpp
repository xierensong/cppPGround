#include<bits/stdc++.h>

using namespace std;

int search_pos(vector<int> &nums, int low, int high)
{
    while(low < high) {
        while(low < high && nums[low] < nums[high]) high--;
        int tmp=nums[low];
        nums[low]=nums[high];
        nums[high]=tmp;
        while(low < high && nums[high] > nums[low]) low++;
        tmp=nums[low];
        nums[low]=nums[high];
        nums[high]=tmp;
    }
    return low;
}

void quick_sort(vector<int> &nums, int low, int high)
{
    if(low < high) {
        int pos = search_pos(nums, low, high);
        quick_sort(nums, low, pos-1);
        quick_sort(nums, pos+1, high);
    }
}

int main()
{
    vector<int> nums{2,3,8,5,18,1,21,7};
    quick_sort(nums, 0, nums.size()-1);
    for(auto num:nums){
        cout << num << ' ';
    }
    cout << endl;
}