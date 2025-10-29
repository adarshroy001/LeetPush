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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ; 
        queue<pair<int,TreeNode*>> q ; 
        q.push({0,root}) ; 
        unsigned long long ans = 0 ; 
        while(!q.empty()){
            int size = q.size() ; 
            unsigned long long mini = q.front().first ;
            unsigned long long first , last ; 
            for(int i = 0 ; i < size ; ++i){
                auto temp = q.front() ;
                unsigned long long currentId = temp.first - mini ; 
                TreeNode* node = temp.second ;
                q.pop() ; 
                if(i == 0) first = currentId ; 
                if(i == size -1) last = currentId ;
                if(node ->left) q.push({currentId * 2 + 1,node->left}) ;
                if(node ->right) q.push({currentId*2 + 2,node->right}) ;
            } 
                ans = max(ans,last - first + 1) ; 
        }
        return ans ; 
    }
};