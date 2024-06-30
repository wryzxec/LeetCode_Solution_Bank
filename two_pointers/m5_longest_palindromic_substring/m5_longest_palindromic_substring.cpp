#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/* 
<-Description->
    Given a string s, return the longest palindromic substring in s.

<-Constraints->
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        int mxl = 0, mxr = 0, mx = 0;

        for(int i = 0; i < n-1; i++){
            // even case
            if(s[i] == s[i+1]){
                int l = i, r = i+1;
                while(l >= 0 && r < n && s[l] == s[r]){
                    l--, r++;
                }
                r--, l++;
                if(r-l+1 > mx){
                    mxl = l, mxr = r, mx = r-l+1;
                }
            }

            // odd case
            if(i > 0 && s[i-1] == s[i+1]){
                int l = i-1, r = i+1;
                while(l >= 0 && r < n && s[l] == s[r]){
                    l--, r++;
                }
                l++, r--;
                if(r-l+1 > mx){
                    mxl = l, mxr = r, mx = r-l+1;
                }
            }
        }
        return s.substr(mxl, mxr-mxl+1);
    }
};

int main(){
    Solution solution;

    string s = "babad";
    cout << solution.longestPalindrome(s);
}