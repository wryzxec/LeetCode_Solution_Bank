#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
    A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.
    Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

<-Constraints->
    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0) dp[i][j] = matrix[i][j];
                else if(j == 0) dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                else if(j == n-1) dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                else dp[i][j] = matrix[i][j] + min(min(dp[i-1][j], dp[i-1][j-1]), min(dp[i-1][j], dp[i-1][j+1]));
            }
        }
        int minPathSum = INT_MAX;
        for(int j = 0; j < n; j++){
            minPathSum = min(minPathSum, dp[n-1][j]);
        }
        return minPathSum;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = 
    {{2,1,3},
     {6,5,4},
     {7,8,9}};
    cout << solution.minFallingPathSum(matrix);
}