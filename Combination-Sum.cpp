class Solution {
public:
    vector<vector<int>> ans ; 

    void helper(vector<int>& candi , vector<int>& v , int tar , int i){
        if(tar == 0){
            ans.push_back(v) ;
            return ;
        }
        if(i == candi.size()){
            if(tar == 0){
                ans.push_back(v) ; 
            }
            return ;
        }
        if(tar < 0) return ;
        // Logic
        v.push_back(candi[i]) ;
        helper(candi,v,tar-candi[i],i) ;
        v.pop_back() ;
        helper(candi,v,tar,i+1) ;

    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v = {}; 
        helper(candidates,v,target,0);
        return ans ; 
    }
};