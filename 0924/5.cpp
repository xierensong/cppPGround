#include<bits/stdc++.h>

using namespace std;

    int getMaxValue_solution(vector<vector<int> > &values) {
        if(values.size()==0) return 0;
        int rows=values.size();
        if(values[0].size()==0) return 0;
        int cols=values[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[0][0]=values[0][0];
        for(int i=1; i<rows;++i) dp[i][0]=dp[i-1][0]+values[i][0];
        for(int j=1; j<cols;++j) dp[0][j]=dp[0][j-1]+values[0][j];
        for(int i=1; i<rows;++i) {
            for(int j=1; j<cols;++j) {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1])+values[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }


int main()
{
    //vector<int> numbers{2,4,13,6};
    //int a=0,b=0;
    vector<vector<int> > values{{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
   int result=getMaxValue_solution(values);
    cout << result << endl;
}