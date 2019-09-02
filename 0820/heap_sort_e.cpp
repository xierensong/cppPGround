#include<bits/stdc++.h>

using namespace std;

void print(vector<int> nums) 
{
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}
void adjust(vector<int> &nums, int low, int high)
{
    int num = nums[low];
    int j;
    cout << low << '\t' << high << endl;
    for(j = low * 2+1; j <= high; j = j * 2+1) {
        if (j < high && nums[j] < nums[j+1]) j++;
        if (num > nums[j]) break;
        nums[low]=nums[j];
        low=j;
        cout << "j " << j << endl;
    } 
    nums[low] = num;
    print(nums);
    cout << "---" << endl;
}
void heap_sort(vector<int> &nums)
{
    //建堆
    int len = nums.size();
    for(int i = len/2-1; i >= 0; --i) {
        adjust(nums, i, len-1);
    }
    print(nums);
    cout << endl;
    for(int i = len-1; i>=1; --i) {
        //交换
        int tmp=nums[0];
        nums[0]=nums[i];
        nums[i]=tmp;
        adjust(nums,0,i-1);
        print(nums);
    }
    print(nums);
}
int main()
{
    vector<int> nums{1,3,15,4,8,5,21,7};

    heap_sort(nums);
}