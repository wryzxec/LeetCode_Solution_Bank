#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

<-Constraints->
    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000 
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if(!root) return res;
        q.push(root);

        while(!q.empty()){
            vector<int> v;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                v.push_back(node -> val);
            }
            res.push_back(v);
        }
        return res;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    /*
         (3) <- 1st level
         /  \
       (9)  (20) <- 2nd level
            /  \
          (15)  (7) <- 3rd level
    */
    
    vector<vector<int>> levelOrderValues = solution.levelOrder(root);
    for(vector<int> level : levelOrderValues){
        for(int value : level){
            cout << value << " ";
        }
        cout << "\n";
    }
}