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
    int ans =INT_MIN ; 
    int helper(TreeNode* root , int sum){
        if(root == NULL){
           return 0 ; 
        }
        int leftMax = max(sum,helper(root->left, sum) );
        int rightMax = max(sum,helper(root->right, sum));

        ans = max(ans, leftMax + rightMax + root->val) ;

        return root->val + max(leftMax,rightMax);

    }
    int maxPathSum(TreeNode* root) {
        helper(root,0) ;
        return ans ;
    }
};