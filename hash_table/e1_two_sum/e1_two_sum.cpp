#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
<-Description->
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.

<-Constraints->
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        int n = nums.size();
        // map{numToFind, index}
        for(int i = 0; i < n; i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp[target - nums[i]], i};
            }
            mp[nums[i]] = i;
        }      
        return {};
    }
};

int main(){

    Solution solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}