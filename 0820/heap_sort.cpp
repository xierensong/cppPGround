#include<bits/stdc++.h>

using namespace std;

void heap_adjust(vector<int> & heap, int low, int high)
{
    cout << low << ' ' << high << endl;
    int rc = heap[low];
    for(int i = low * 2+1; i <= high; i=i*2+1) {
        if(i < high && heap[i] < heap[i+1]) i++;
        if (rc < heap[i]) {
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
    for(int i = heap.size() / 2-1; i >= 0; --i) {
        heap_adjust(heap, i, heap.size()-1);
    }
    for(int num : heap) {
        cout << num << ' ';
    }
    cout << "-" << endl;
    cout << endl;
    //依次输出堆顶元素
    for(int i = heap.size()-1; i >= 0; --i) {
            for(int num : heap) {
        cout << num << ' ';
    }
    cout << "-" << endl;
        //cout << heap[0] << ' ';
        int tmp = heap[0];
        heap[0] = heap[i];
        heap[i] = tmp;   
                            for(int num : heap) {
        cout << num << ' ';
    }
    cout << "-" << endl;     
        heap_adjust(heap, 0, i-1);
                    for(int num : heap) {
        cout << num << ' ';
    }
    cout << "-" << endl;
    cout << endl;
    }
    return 0;
}