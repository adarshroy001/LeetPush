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

 //M-1 using level order traversal and putting rightmost element in ans vector 
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root) return {}; 
//         queue<TreeNode*> q ; 
//         q.push(root) ; 
//         vector<vector<int>> v ;
//         while(!q.empty()){
//             int size = q.size() ; 
//             vector<int> ans ; 
//             for(int i = 0 ; i < size ; ++i){
//                  TreeNode* front = q.front() ; 
//                  q.pop() ; 
//                  ans.push_back(front->val) ; 
//                  if(front->left) q.push(front->left) ; 
//                  if(front->right) q.push(front->right) ; 
//             }
//             v.push_back(ans) ;
//         }
//         vector<int> res(v.size()) ; 
//         for(int i = 0 ; i < v.size() ; i++){
//             res[i] = v[i][v[i].size()-1] ;
//         }
//         return res ;
//     }
// };


//M-2 using recurssion and map and checking corrosponding to key
class Solution {
public:
    map<int , int >  m ; 
    vector<int> ans ; 
    void helper(TreeNode* root , int lvl){
        if(!root) return ; 
        if(!m.count(lvl)){
            m[lvl] ++  ;
            ans.push_back(root->val) ; 
        }
        helper(root->right, lvl+1) ;
        helper(root->left , lvl+1) ;
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root,0) ; 
        return ans ; 
    }
};