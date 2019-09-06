#include<bits/stdc++.h>

using namespace std;

void print(vector<int> nums) {
    for(auto num :nums) {
        cout << num << ' ';
    }
    cout << endl;
}

void merge(vector<int> nums1, vector<int> &nums2, int low, int mid, int high)
{
    cout << "merge " << low << ' ' << high << endl;
    if(low == high) {
        return ;
    }
    int i = low, j = mid+1;
    int k = low;
    while(i <= mid && j <= high) {
        if (nums1[i] < nums1[j]) {
            nums2[k]= nums1[i];
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
    while (j <= high) {
        nums2[k]=nums1[j];
        j++;
        k++;
    }    
}

//nums归并到nums2
void merge_sort(vector<int> nums, vector<int> &nums2, int low, int high)
{
    if(low == high) {
        nums2=nums;
    }
    else {
        int mid = (low+high)/2;
        vector<int> nums1=nums;
        merge_sort(nums,nums1, low, mid);
        merge_sort(nums,nums1, mid+1, high);
        cout << "m" << endl;
        print(nums1);
        merge(nums1, nums2, low, mid, high);
        cout << "mm" << endl;
        print(nums2);
    }
}

int main()
{
    vector<int> nums{1,8,10,5,2,300,20};
    merge_sort(nums,nums, 0, nums.size()-1);
    print(nums);
}