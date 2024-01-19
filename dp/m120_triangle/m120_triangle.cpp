#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    Given a triangle array, return the minimum path sum from top to bottom.
    For each step, you may move to an adjacent number of the row below. 
    More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

<-Constraints->
    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -104 <= triangle[i][j] <= 104 
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        vector<vector<int>> dp;
        for(int i = 0; i < m; i++){
            int n = triangle[i].size();
            vector<int> row(n, 0);
            dp.push_back(row);
        }

        dp[m-1] = (triangle[m-1]);
        for(int i = m-2; i >= 0; i--){
            int n = triangle[i].size();
            for(int j = 0; j < n; j++){
                dp[i][j] = triangle[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution solution;
    vector<vector<int>> triangle =
     {{2},
     {3,4},
    {6,5,7},
   {4,1,8,3}};
   cout << solution.minimumTotal(triangle);
}