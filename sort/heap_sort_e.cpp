#include<bits/stdc++.h>

using namespace std;

void print(vector<int> &nums)
{
    for(int a : nums) {
        cout << a << ' ';
    }
    cout << endl;
}

void heap_adjust(vector<int> &nums, int low, int high)
{
    int tmp=nums[low];
    for(int j=low*2+1; j <= high; j=j*2) {
        if(j<high && nums[j] < nums[j+1]) j=j+1;
        if(nums[low]<nums[j]) {
            int tmp=nums[low];
            nums[low]=nums[j];
            nums[j]=tmp;
            low=j;
        }
        else {
            break;
        }
    }
}

void heap_sort(vector<int> &nums)
{
    //初始化堆
    int len=nums.size();
    for(int i = len/2-1; i >= 0; i--) {
        heap_adjust(nums, i, len-1);
        cout << i << endl;
        print(nums);
    }
    print(nums);
    //输出
    for(int i = len-1; i>=0; --i) {
        int tmp=nums[0];
        nums[0]=nums[i];
        nums[i]=tmp;
        heap_adjust(nums, 0, i-1);
    }
}


int main()
{
    vector<int> nums{1,20,100,80,15,50,200,150};
    heap_sort(nums);
    print(nums);
}