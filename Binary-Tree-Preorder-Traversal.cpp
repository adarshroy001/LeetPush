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
    vector<int> preorderTrav(TreeNode* root , vector<int> &v){
       if(root == NULL) return v ; 
       v.push_back(root->val) ; 
       preorderTrav(root->left,v) ; 
       preorderTrav(root->right,v) ;
       return v ; 
    }

    vector<int> preorderTraversal(TreeNode* root) {
        //Itrative (we need a stack Tc->O(N))
    //     stack<TreeNode *> st ; 
    //     vector<int> v ;
    //     if(root == NULL) return v ; 
    //     st.push(root) ; 
    //     while(!st.empty()){
    //       TreeNode* temp = st.top() ; 
    //       st.pop() ; 
    //       v.push_back(temp->val) ; 
    //       if(temp->right != NULL ) st.push(temp->right) ; 
    //       if(temp->left != NULL ) st.push(temp->left) ;
    //     }
    //     return v ;
    // 
    
    
     //Recussive 
        vector<int> v ;
        preorderTrav(root , v) ; 
        return v; 
    
    }
};