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
    vector<string> ans ; 
    bool isLeaf(TreeNode* node){
        return (node->left == NULL && node->right == NULL) ; 
    }
    void helper(TreeNode* root , string s){
        if(!root) return ; 
        string str = to_string(root->val) ; 
        if(isLeaf(root)){
            s = s + str ; 
            ans.push_back(s) ; 
        }else{
            s = s + str + "->" ; 
        }
        if(root->left) helper(root->left , s) ; 
        if(root->right) helper(root->right ,s) ; 

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "" ; 
        if(!root) return ans ; 
        helper(root,s) ;
        return ans ; 
    }
};