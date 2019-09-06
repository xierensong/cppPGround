#include<bits/stdc++.h>

using namespace std;

void print(vector<int> nums)
{
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

int depart(vector<int> &nums, int i, int j)
{
    while(i < j) {
        int value=nums[i];
        while( i<j && nums[j]> value) j--;
        int tmp=nums[j];
        nums[j]=nums[i];
        nums[i]=tmp;
        while (i<j && nums[i]<value) i++;
        tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;       
    }
    return i;
}

void quick_sort(vector<int> &nums, int i, int j)
{
    if (i < j) {
        int pos = depart(nums, i, j);
        quick_sort(nums, i, pos-1);
        quick_sort(nums, pos+1, j);
    }
}

int main()
{
    vector<int> nums{1,3,100,20,11,9,25};
    quick_sort(nums,0,nums.size()-1);
    print(nums);
}