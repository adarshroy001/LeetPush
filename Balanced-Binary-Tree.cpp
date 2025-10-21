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
    // Brute solution Tc - O(N^2) 
    // int calHeight(TreeNode* half){  
    //     if (half == NULL) return 0 ; 
    //     return (1 + max(calHeight(half->right),calHeight(half->left))) ;
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL) return true;
    //     int lftHalf = calHeight(root->left) ; 
    //     int rhtHalf = calHeight(root->right) ; 
    //     if(abs(lftHalf - rhtHalf) > 1 ) return false  ;
    //     if(isBalanced(root->left) && isBalanced(root->right)) return true ; 
    //     return false ; 
    // }


    //Optimal (Tc- O(N))
        int calHeight(TreeNode* root){  
            if (root == NULL) return 0 ; 
            int leftHalf = calHeight(root->left); 
            int rightHalf = calHeight(root->right) ;
            if(leftHalf == -1 || rightHalf == -1) return -1 ;  
            if(abs(leftHalf - rightHalf) > 1) return -1 ; 
            return (1 + max(leftHalf,rightHalf)); 
         }

        bool isBalanced(TreeNode* root) {
            return (calHeight(root) != -1) ; 
    } 
};