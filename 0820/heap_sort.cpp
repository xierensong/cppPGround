#include<bits/stdc++.h>

using namespace std;

void heap_adjust(vector<int> & heap, int low, int high)
{
    int rc = heap[low];
    for(int i = low * 2; i <= high; i=i*2) {
        if(i < high && heap[i] < heap[i+1]) i++;
        if (heap[low] < heap[i]) {
            heap[low]=heap[i];
            low=i;
        }
        else {
            break;
        }
    }
    heap[low]=rc;
}

int main() 
{
    vector<int> heap{2,5,1,10,12,7,3,13};

    //构建大顶堆
    for(int i = heap.size() / 2; i >= 0; --i) {
        heap_adjust(heap, i, heap.size()-1);
    }
    //依次输出堆顶元素
    for(int i = heap.size(); i >= 1; --i) {
        int tmp = heap[i];
        heap[i] = heap[0];
    }
    return 0;
}