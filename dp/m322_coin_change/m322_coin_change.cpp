#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the fewest number of coins that you need to make up that amount.
    If that amount of money cannot be made up by any combination of the coins, return -1.
    You may assume that you have an infinite number of each kind of coin.

<-Constraints->
    1 <= coins.length <= 12
    1 <= coins[i] <= 2^31 - 1
    0 <= amount <= 10^4  
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    
        int max = amount + 1;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){

                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
int main(){
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int change = 11;
    cout << solution.coinChange(coins, change);
}