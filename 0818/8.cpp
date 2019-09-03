#include<bits/stdc++.h>

using namespace std;

main()
{
    int N;
    cin >> N;
    vector<long long> H;
    int tmp = N;
    while(tmp--) {
        long long hi;
        cin >> hi;
        H.push_back(hi);
    }
    vector<long long> ups,downs;
    long long max_val=LONG_LONG_MIN, min_val=LONG_LONG_MAX;

    for(int i = 0; i != N; i ++) {
        if (H[i] > max_val) {
            max_val=H[i];            
        }
        //ups[i]=max_val;
        ups.push_back(max_val);
        cout << "23 " << max_val << endl;
        if (H[N-1-i] < min_val) {
            min_val=H[N-1-i];            
        }
        //downs[N-1-i]=min_val;
        downs.insert(downs.begin(), min_val);
       cout << "24 " << min_val << endl;
    }
    
    cout << ups.size() << downs.size() << endl;
    for(int i = 0; i != N; i ++) {
        cout << H[i] << ' ' << downs[i] << ' ' << ups[i] << endl;
    }
    cout << endl;
    int cnt = 0;
    int curr_down = downs[0];
    int curr_up = ups[0];
    for(int i = 1; i!= N; i++) {
        if (downs[i] == curr_down && ups[i] == curr_up) continue;
        if (downs[i] >= curr_up) {
            cnt++;
        }
        curr_up = ups[i];
        curr_down = downs[i];
    }
    cout << cnt + 1 << endl;
    return 0;
}