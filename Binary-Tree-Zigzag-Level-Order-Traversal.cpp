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
    vector<vector<int>> ans ; 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return ans; 
        queue<TreeNode*> q ; 
        q.push(root) ; 
        bool isRight = false ; 
        while(!q.empty()){
            int size = q.size() ; 
            vector<int> v(size); 
            for(int i = 0 ; i < size ;i++){
                TreeNode* temp = q.front() ; 
                q.pop();
                    int index = isRight? size - 1 -i : i;
                    v[index] = temp->val;
                    if(temp->left != NULL) q.push(temp->left);
                    if(temp->right != NULL) q.push(temp->right);
            }
            isRight = !isRight ;
            ans.push_back(v);
        }
        return ans ; 
    }
};