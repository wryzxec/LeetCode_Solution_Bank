#include <bits/stdc++.h>
#include <iostream>

using namespace std;


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