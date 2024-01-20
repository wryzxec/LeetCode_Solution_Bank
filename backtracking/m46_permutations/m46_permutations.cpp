#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

<-Constraints->
    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.
*/

class Solution {
public:
    void permutations(vector<vector<int>> &res, vector<int> temp, vector<int> &nums){
        
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            permutations(res, temp, nums);
            temp.erase(temp.end()-1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        permutations(res, temp, nums);
        return res;
    }
};

int main(){
    Solution Solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = Solution.permute(nums);
    for(vector<int> permutation : permutations){
        for(int num : permutation) cout << num << " ";
        cout << "\n";
    }

    /*
                                        [1,2,3]
                                      /    |    \
                               [1,2,3]  [2,1,3]  [3,2,1]
                            /     |     /     \      |    \
                    [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]
    */
}