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
    int distance = 0 ; 
    int calHeight(TreeNode* root) {
        if(root == NULL) return 0 ; 
        int lefthalf = calHeight(root->left) ; 
        int righthalf = calHeight(root->right) ;
        distance = max(distance , lefthalf + righthalf); 
        return (1 + max(lefthalf, righthalf)) ; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0 ; 
        calHeight(root) ; 
        return distance ; 
    }
};