#include<bits/stdc++.h>

using namespace std;

void print(vector<int> nums)
{
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

int partition(vector<int> &nums, int low, int high)
{
    int val=nums[low];
    while(low<high) 
    {
        while(low<high && nums[high]>val) {
            high--;
        }
        int tmp=nums[high];
        nums[high]=nums[low];
        nums[low]=tmp;
        while(low<high && nums[low]<val) {
            low++;
        }
        tmp=nums[low];
        nums[low]=nums[high];
        nums[high]=tmp;
    }
    return low;
    return 0;
}

void quick_sort(vector<int> &nums, int low, int high)
{
    if(low < high) {
        int pos=partition(nums,low,high);
        //cout << "pos " << pos << endl;
        quick_sort(nums,low,pos-1);
        quick_sort(nums,pos+1,high);
    }
}

int main()
{
    vector<int> nums{1,10,7,20,15,11,100,75};
    print(nums);
    quick_sort(nums,0,nums.size()-1);
    print(nums);
    return 0;
}