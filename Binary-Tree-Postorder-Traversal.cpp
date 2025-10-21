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
    void TravPost(TreeNode* root , vector<int> &v){
        if(root == NULL) return  ; 
        TravPost(root->left,v) ;
        TravPost(root->right,v) ; 
        v.push_back(root->val) ; 
    }
    vector<int> postorderTraversal(TreeNode* root) {
        //Recurssive 
        // vector<int> v;  
        // TravPost(root,v) ; 
        // return v ; 

        //Itrative (using 2 stack)
        // vector<int> v; 
        // if(root == NULL) return v ;
        // stack<TreeNode*> st1 , st2 ; 
        // st1.push(root) ; 
        // while(!st1.empty()){
        //     TreeNode* temp = st1.top() ; 
        //     st1.pop() ; 
        //     if(temp->left != NULL){
        //         st1.push(temp->left) ; 
        //     }
        //     if(temp->right != NULL){
        //         st1.push(temp->right) ; 
        //     }
        //     st2.push(temp) ; 
        // }
        // while(!st2.empty()){
        //     v.push_back(st2.top()->val) ; 
        //     st2.pop() ; 
        // }
        // return v ; 

        //Itrative solution (Using 1 stack) 
        TreeNode* curr = root ; 
        vector<int> v ; 
        stack<TreeNode*> st ; 
        if(root == NULL) return v ; 
        while(curr != NULL || !st.empty()){
          if(curr != NULL){
            st.push(curr); 
            curr = curr->left ; 
          }else{
            TreeNode* temp = st.top()->right ; 
            if(temp == NULL){
                temp = st.top() ; 
                st.pop() ; 
                v.push_back(temp->val) ; 
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top() ;
                    st.pop() ; 
                    v.push_back(temp->val) ; 
                }
            }else{
                curr = temp ; 
            }

          }

        }
        return v ;
        
    }
};