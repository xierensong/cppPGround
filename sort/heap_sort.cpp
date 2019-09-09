#include<bits/stdc++.h>

using namespace std;

void heap_adjust(vector<int> & heap, int low, int high) {
    int rc = heap[low];
    for(int i = low*2 + 1; i <= high; i=i*2+1) {
        if (i< high && heap[i]<heap[i+1]) i++;
        if(heap[i]<rc) {
            break;
        }
        else {
            heap[low]=heap[i];
            low=i;
        }
    }
    heap[low]=rc;
}
int main()
{
    vector<int> heap{10,1,8,5,7,20,100,85};
    //建堆
    for(int i = heap.size()/2 - 1; i >= 0; --i) {   //最后一个分支
        heap_adjust(heap,i,heap.size()-1);
    }

    //排序
    for(int i = heap.size()-1; i > 0; --i) {
        int tmp=heap[0];
        heap[0]=heap[i];
        heap[i]=tmp;

        heap_adjust(heap, 0, i-1);
    }

    for(auto a : heap) {
        cout << a << ' ';
    }
    cout << endl;
}