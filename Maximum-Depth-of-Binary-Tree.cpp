/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL ) return 0 ; 
        vector<vector<int>> leveltree ; 
        queue<TreeNode*> q ;
        q.push(root) ; 
        while(!q.empty()){
          int size = q.size() ; 
          vector<int> v ; 
          for(int i = 0 ; i < size ; i++){
            TreeNode* newNode = q.front() ; 
             q.pop() ; 
             if(newNode->left != NULL) q.push(newNode->left) ;
             if(newNode->right != NULL) q.push(newNode->right) ;
             v.push_back(newNode->val) ; 
          }
          leveltree.push_back(v) ; 
        }
        int count = 0 ; 
        for(auto &ans : leveltree){
            count++; 
        }
        return count ; 
    }
};