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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numberOfRooms = rooms.size(), roomsVisited = 1;
        vector<bool> visited(numberOfRooms, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            vector<int> v = rooms[q.front()];
            q.pop();
            for(int i : v){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    roomsVisited++;
                    if(roomsVisited == numberOfRooms) return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution Solution;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    cout << Solution.canVisitAllRooms(rooms);
}