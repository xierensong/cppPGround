#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &nums, int low, int high) {
    int tmp=nums[low];
    while(low < high) {
        //cout << '1' << endl;
        while(low < high && nums[high] > tmp) high--;
        nums[low]=nums[high];
        while(low < high && nums[low] < tmp) low++;
        nums[high]=nums[low];
    }
    nums[low]=tmp;
    return low;
}

void quick_sort(vector<int> &nums, int low, int high) {
    //cout << low << ' ' << high << endl;
    if(low < high) {
        int idx = partition(nums, low, high);
        quick_sort(nums,0,idx-1);
        quick_sort(nums,idx+1,high);
    }
}

int main()
{
    vector<int> nums{8,7,6,10,20,32,19,12};
    //cout << '1' << endl;
    quick_sort(nums, 0, nums.size()-1);
    for(auto num:nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}