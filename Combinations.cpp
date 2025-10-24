class Solution {
public:
    vector<vector<int>> ans  ; 
    void helper(int n , int k ,vector<int> &v){
        if(v.size() == k ){
            ans.push_back(v) ;
            return ;
        }
        if(n == 0) return;
        v.push_back(n);
        helper(n-1, k , v);
        v.pop_back() ; 
        helper(n-1, k , v);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v ; 
        helper(n,k,v) ; 
        return ans ; 
    }
};