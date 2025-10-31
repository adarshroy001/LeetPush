/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void connectParent(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &p){
         if(!root) return ; 
         if(root->left){
            p[root->left] = root ; 
            connectParent(root->left,p) ; 
         }
        if(root->right){
            p[root->right] = root ; 
            connectParent(root->right,p) ; 
         }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode*,TreeNode*> p;
         connectParent(root,p) ;
         queue<TreeNode*> q ; 
         unordered_map<TreeNode*,bool> visited;
         int distance = 0 ; 
         q.push(target) ; 
         visited[target] = true ;
         while(!q.empty()){
            if(distance++ == k) break ;  
            int size = q.size() ; 
            for(int i = 0 ; i < size ; ++i){
                auto temp = q.front() ;
                q.pop() ;
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left) ; 
                    visited[temp->left] = true ; 
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right) ; 
                    visited[temp->right] = true ; 
                }  
                if(p[temp] && !visited[p[temp]]){
                    q.push(p[temp]);
                    visited[p[temp]] = true;
                }
            }
         } 
         vector<int> ans;
         while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
         }
       return ans;  
     }
};