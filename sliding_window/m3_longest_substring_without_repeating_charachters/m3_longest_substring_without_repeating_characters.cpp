#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/* 
<-Description->
    Given a string s, find the length of the longest substring without repeating characters.

<-Constraints->
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;
        int mx = 0;
        int l = 0, r = 0;
        int n = s.size();

        while(r < n){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            mx = max(mx, r - l + 1);
            st.insert(s[r]);
            r++;
        }
        return mx;
    }
};

int main(){
    Solution solution;

    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s);
}