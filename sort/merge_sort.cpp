#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> nums, vector<int> &nums1, int low, int mid, int high) {
        int i=low, j=mid+1, k=low;
        cout << "merge" << '\t' << low << '\t' << mid << '\t' << high << endl;
        for(auto num : nums1) {
            cout << num << ' ';
        }
        cout << endl;
        while(i <= mid && j <= high) {
            nums1[k] = (nums[i]<nums[j]) ? nums[i++] : nums[j++];
            k++;
        }
        while(i <= mid) {
            nums1[k]=nums[i];
            i++,k++;
        }
        while(j <= high) {
            nums1[k]=nums[j];
            j++,k++;
        }

}


void merge_sort(vector<int> nums, vector<int> &nums1, int low, int high) {
    cout << "merge_sort " << low << ' ' << high << endl;
    if (low == high) {  //终止条件
        nums1[low]=nums[low];
    } 
    else {
        vector<int> nums2=nums;
        int mid = low + (high-low) / 2;
        merge_sort(nums, nums2, low, mid);
        merge_sort(nums, nums2, mid+1, high);
        cout << "nums1 " << endl;
        for(auto num : nums1) {
            cout << num << ' ';
        }
        cout << endl;
        merge(nums2, nums1, low, mid, high);
        cout << "nums " << endl;
        for(auto num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    cout << "merge_sort end " << low << ' ' << high << endl;
}

int main()
{
    vector<int> nums{2,10,4,44,5,1,500,20,8,99};
    merge_sort(nums, nums, 0, nums.size()-1);
    for(int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}