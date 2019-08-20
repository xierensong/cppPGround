#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int nums[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> nums[i][j];
        }
    }
    int t = N * M, empty=0, smaller = 0, all= 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int v = nums[i][j];
            if (v==0) {
                empty++;
                continue;
            }
            all += v;
            if (j > 0) {
                smaller += min(nums[i][j], nums[i][j-1]);
            }
            if (i > 0) {
                smaller += min(nums[i][j], nums[i-1][j]);
            }
        }
    }
    cout << 4 * all + 2 * t - 2 * smaller - 2 * empty << endl;
}