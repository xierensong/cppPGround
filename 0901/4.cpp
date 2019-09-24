#include<bits/stdc++.h>

using namespace std;

int convert(int n, int base) 
{
    int res=0;
    stack<int> my_stack;
    while(n % base != 0 || n / base != 0) {
        int a = n % base;
        n = n / base;
        if (a >= 10) return -1;
        my_stack.push(a); 
    }
    while(!my_stack.empty()) {
        int a = my_stack.top();
        my_stack.pop();
        res = res*10 + a;
    }
    return res;
}

int main()
{
    int n, x;
    
    cin >> n >> x;
    if(x > n) {
        cout << 10 << endl;
        return 0;
    }
    int low = 10;
    int high = n;
    int y = x;
    while(low <= high) {
        int mid = low + (high-low) / 2;
        int res = convert(n, mid);
        //cout << "base " << base << " res " << res << endl;
        if (res > x)  low = mid;
        else if(res==x) {
            y=res;
            break;
        }
        else {
            if(res == -1) {
                
            }
            else {
                high = mid;
            }
        }      
    }
    cout << y << endl;
}