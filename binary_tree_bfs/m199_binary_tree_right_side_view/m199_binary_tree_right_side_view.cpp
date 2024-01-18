#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*  
<-Description->
    Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

<-Constraints->
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return res;
        q.push(root);

        while(!q.empty()){
            int n = q.size(), rightNodeVal;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                rightNodeVal = node -> val;
            }
            res.push_back(rightNodeVal);
        }
        return res;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> right = new TreeNode(4);
    root -> left -> right -> left = new TreeNode(5);
    root -> left -> right -> right = new TreeNode(6);

    /*
            (1)
            / \
          (2) (3)
            \
            (4)
            / \
          (5) (6)        
    */

   vector<int> rightSideValues = solution.rightSideView(root);
   for(int i : rightSideValues){
        cout << i << " ";
   }
}