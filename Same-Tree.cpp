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
    bool sign = true ;

    void helper(TreeNode* p, TreeNode* q) {
        //base case 
        if(p == NULL && q == NULL) return ;
        if((p == NULL && q != NULL) || (q == NULL && p != NULL)) {
            sign = false ; 
            return ; 
        }
        //compare 
        if((p->val != q->val)){
            sign = false ; 
        }
        else{
            helper(p->left , q->left) ;
            helper(p->right, q->right) ;
        }

    }

    bool isSameTree(TreeNode* p, TreeNode* q) { 
        helper(p,q) ; 
        return sign ;
    }
};