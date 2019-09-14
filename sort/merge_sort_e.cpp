#include<bits/stdc++.h>

using namespace std;

void print(vector<int> nums1) {
    for(auto num : nums1) {
        cout << num << ' ';
    }
    cout << endl;
}

void merge(vector<int> nums1, vector<int> &nums2, int low, int pos, int high)
{
    int i=low,j=pos+1;
    int k=low;
    while(i<=pos && j <= high) {
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
    while(i<=pos) {
        nums2[k]=nums1[i];
        i++;k++;
    }
    while(j<=high) {
        nums2[k]=nums1[j];
        j++;k++;
    }
    return;
}

void merge_sort(vector<int> nums1, vector<int> &nums2, int low, int high)
{
    if(low >= high) {
        return;
    }
    else {
        int pos=(low+high)/2;
        vector<int> nums0=nums1;
        merge_sort(nums1, nums0, low, pos);
        merge_sort(nums1, nums0, pos+1, high);
        merge(nums0, nums2, low, pos, high);
    }
}

int main()
{
    vector<int> nums{1,23,100,50,120,40,150};
    merge_sort(nums,nums,0,nums.size()-1);
    print(nums);
}