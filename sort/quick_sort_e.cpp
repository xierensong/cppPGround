#include<bits/stdc++.h>

using namespace std;

int patition(vector<int> &nums, int low, int high)
{
    int pivot=nums[low];
    while(low<high) {
        while(low<high&&nums[high]>pivot) high--;
        int tmp=nums[low];
        nums[low]=nums[high];
        nums[high]=tmp;
        while(low<high&&nums[low]<pivot) low++;
        tmp=nums[low];
        nums[low]=nums[high];
        nums[high]=tmp;
    }
    return low;
}

void quick_sort(vector<int> &nums, int low, int high)
{
    if(low < high) {
        int pos = patition(nums, low, high);
        quick_sort(nums, low, pos-1);
        quick_sort(nums, pos+1, high);
    }
}

int main()
{
    vector<int> my_nums{1,100,50,20,150,35,70};
    quick_sort(my_nums, 0, my_nums.size()-1);
    for(const int &num : my_nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}