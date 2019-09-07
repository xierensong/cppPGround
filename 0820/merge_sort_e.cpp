#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> nums1, vector<int> &nums2, int low, int mid, int high)
{
    int i = low, j = mid+1;
    int k = low;
    while(i <= mid && j <= high) {
        if (nums1[i] <nums1[j]) {
            nums2[k]=nums1[i];
            i++;
        }
        else {
            nums2[k]=nums1[j];
            j++;
        }
        k++;
    }
    while(i <= mid) {
        nums2[k]=nums1[i];
        i++;
        k++;
    }
    while(j <= high) {
        nums2[k]=nums1[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> nums1, vector<int> &nums2, int low, int high)
{
    cout << "wer" << endl;
    if (low == high) {
        nums2=nums1;
    }
    else {
        int mid = (low+high)/2;
        vector<int> nums3=nums1;
        merge_sort(nums1, nums3, low, mid);
        merge_sort(nums1, nums3, mid+1, high);
        for(auto num : nums3) {
            cout << num << " ";
        }
        cout << endl;
        merge(nums3,nums2,low,mid,high);
    }
}

int main()
{
    cout << "werq" << endl;
    vector<int> nums{10,2,5,9,100,27,6};
    merge_sort(nums,nums,0,nums.size()-1);
    cout << "werw" << endl;
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}