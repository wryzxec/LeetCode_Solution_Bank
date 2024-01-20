#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.
    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
    The same letter cell may not be used more than once.

<-Constraints->
    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.
*/

class Solution {
public:
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word, int charIndex) {
        int m = board.size(), n = board[0].size();

        if (charIndex == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[charIndex] || visited[i][j]) return false;
        
        visited[i][j] = true;

        bool found = search(board, visited, i - 1, j, word, charIndex + 1) ||
                     search(board, visited, i + 1, j, word, charIndex + 1) ||
                     search(board, visited, i, j - 1, word, charIndex + 1) ||
                     search(board, visited, i, j + 1, word, charIndex + 1);

        visited[i][j] = false;
        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size(), n = board[0].size(), charIndex = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && search(board, visited, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> board = 
    {{'A', 'B', 'C', 'E'},
     {'S', 'F', 'C', 'S'}, 
     {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << solution.exist(board, word); 
}