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
//Tc- O(N)
    // int countNodes(TreeNode* root) {
    //     if(!root) return 0;
    //     return 1 + countNodes(root->left) + countNodes(root->right);
    // }

    //Tc-O(logN) 
        int countLeft (TreeNode* root){
            if(!root) return 0 ; 
            return 1 + countLeft(root->left) ; 
        }
        int countRight (TreeNode* root){
            if(!root) return 0 ; 
            return 1 + countRight(root->right) ; 
        }
        int countNodes(TreeNode* root) {
          if(root == NULL) return 0 ; 
          int lh =  countLeft(root) ; 
          int rh = countRight(root) ; 
          if(lh == rh) return pow(2,lh) - 1 ; 
          return 1  + countNodes(root->left) + countNodes(root->right) ; 
    }
};