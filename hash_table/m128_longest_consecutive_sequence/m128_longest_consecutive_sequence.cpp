Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

<-Constraints->
    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        int longest = 1;
        unordered_set<int> st;

        for (int num : nums){
            st.insert(num);
        }

        for(auto it: st){
            if (st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;

                while(st.find(x+1) != st.end()){
                    cnt++;
                    x += 1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};

int main(){

    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << solution.longestConsecutive(nums);
}