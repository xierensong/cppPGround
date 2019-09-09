#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res=0;
    vector<int> nums(n+1);
    int i,j;
    for(i=1,j=1;;i++,j++) {
        if(j==5&&i==n&&nums[i]==0){
            cout << res+1 << endl;
            break;
        }
        if(nums[i]==1){
            j--;
            continue;
        }
        if(j==5){
            nums[i]=1;
            res++;
            j=0;
        }
        if(i==n){
            i=0;
        }        
    }
}