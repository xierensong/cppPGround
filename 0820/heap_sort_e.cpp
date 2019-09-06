#include<bits/stdc++.h>

using namespace std;

void print(vector<int> &nums) 
{
    for(auto num:nums) {
        cout << num << ' ';
    }
    cout << endl;
}

void adjust(vector<int> &nums, int low, int high)
{
    cout << low << ' ' << high << endl;
    int tmp=nums[low];
    for (size_t i = low*2+1; i <= high ; i = i*2)
    {
        if (i < high && nums[i+1] > nums[i]) i++;
        if(nums[low] > nums[i]) break;
        nums[low] = nums[i];
        low=i;
    }
    nums[low]=tmp;    
}

void heap_sort(vector<int> &nums)
{
    int len = nums.size();
    for(int i = len/2-1; i >= 0; --i) {
        adjust(nums, i, len-1);
    }
    print(nums);
    for(int i=len-1;i>=1;--i) {
        int tmp=nums[0];
        nums[0]=nums[i];
        nums[i]=tmp;
        cout << "wewer" << endl;
        print(nums);
        adjust(nums,0,i-1);
        cout << "last" << endl;
        print(nums);
    }
}

int main()
{
    vector<int> nums{1,3,100,30,8,15,20,7,45};
    heap_sort(nums);
    print(nums);
}