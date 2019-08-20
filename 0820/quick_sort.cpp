#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> & nums, int low, int high) {
    int key= nums[low];
    //cout << "enter partition" << endl;
    while(low < high) {
        while(low < high && nums[high] > key) {
            high --;
        }
        nums[low]=nums[high];   //high值移动到左半部分
        while (low < high && nums[low] < key)
        {
            low++;
        }
        nums[high]=nums[low];
    }
    nums[low]=key;
    return low;
}

void quick_sort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int idx = partition(nums, low, high);
        //cout << idx << endl;
        quick_sort(nums, 0, idx-1);
        quick_sort(nums, idx+1, high);
    }
}

int main()
{
    vector<int> nums{5, 8, 3, 1, 15, 11, 30};
    //cout << 2 << endl;
    quick_sort(nums, 0, nums.size()-1);
    //
    cout << 1 << endl;
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}