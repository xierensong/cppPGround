#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> nums1, vector<int> &nums2, int low, int mid, int high)
{
    int i=low,j=mid+1,k=low;
    while(i<=mid && j <= high) {
        if(nums1[i]<nums1[j]) {
            nums2[k]=nums1[i];
            i++;
        }
        else {
            nums2[k]=nums1[j];
            j++;
        }
        k++;
    }
    while(i<=mid) {
        nums2[k]=nums1[i];
        i++;
        k++;
    }
    while(j<=high) {
        nums2[k]=nums1[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> nums, vector<int> &nums2, int low, int high)
{
    if(low >= high) {
        return;
    }
    else {
        vector<int> nums1=nums;
        int mid = low + (high-low)/2;
        merge_sort(nums, nums1,low, mid);
        merge_sort(nums, nums1, mid+1, high);
        merge(nums1, nums2, low, mid, high);
    }
}

int main() 
{
    vector<int> nums{10,1,22,25,23,7,100,11};
    merge_sort(nums,nums,0,nums.size()-1);
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}