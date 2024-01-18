#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0.
    Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
    When you visit a room, you may find a set of distinct keys in it. 
    Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
    Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
    
<-Constraints->
    n == rooms.length
    2 <= n <= 1000
    0 <= rooms[i].length <= 1000
    1 <= sum(rooms[i].length) <= 3000
    0 <= rooms[i][j] < n
    All the values of rooms[i] are unique.
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int m = isConnected.size(), provinceCount = 0;
        queue<int> q;
        vector<bool> visited(m, false);
        
        for(int i = 0; i < m; i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()){
                    int node = q.front();
                    int n = isConnected[node].size();
                    visited[node] = true;
                    q.pop();
                    for(int j = 0; j < n; j++){
                        if(i != j && !visited[j] && isConnected[node][j]){
                            q.push(j);
                        }
                    }
                }
                provinceCount++;
            }
        }
        return provinceCount;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
    cout << solution.findCircleNum(isConnected);
}