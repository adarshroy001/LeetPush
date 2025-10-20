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
    void InTrav(TreeNode* root , vector<int> &v){
        if(root == NULL ) return ; 
        InTrav(root->left ,v) ; 
        v.push_back(root->val) ; 
        InTrav(root->right,v) ; 
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Recurssive 
        // vector<int> v ; 
        // InTrav(root, v) ; 
        // return v; 

       
        //Itrative 
        vector<int> v ;  
        stack<TreeNode*> st ;
        TreeNode* temp = root ;  
        while(true){
            if(temp != NULL) {
               st.push(temp) ; 
               temp = temp->left ;  
            }
            else{
                if(st.empty()){
                    break ; 
                }else{
                    temp = st.top() ;
                    st.pop() ; 
                    v.push_back(temp->val) ; 
                    temp = temp->right ;  
                }
            }
        }
        return v ;
    }
};