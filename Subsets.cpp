class Solution {
public:
    //Helper function 
    void helper(vector<int>& nums , vector<vector<int>> &v , int i , vector<int>& subset){
        //Base Case
        if(nums.size() == i){
            v.push_back(subset) ;
            return ; 
        } 
        subset.push_back(nums[i]) ;          
        helper(nums,v,i+1 , subset) ;
        subset.pop_back() ; 
        helper(nums,v,i+1,subset) ; 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v = {}; 
        vector<int> subset ; 
        helper(nums,v,0,subset) ;
        return v; 
    }
};