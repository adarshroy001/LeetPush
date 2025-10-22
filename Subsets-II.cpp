class Solution {
public:
    void helper(vector<int>& nums , vector<vector<int>> &v , int i , vector<int>& subset , map<vector<int>, int> &m){
        //Base Case
        if(nums.size() == i){
            if(m[subset] == 0){
            v.push_back(subset) ;
            m[subset] ++ ; 
            }
            return ; 
        } 
        subset.push_back(nums[i]) ;          
        helper(nums,v,i+1 , subset , m) ;
        subset.pop_back() ; 
        helper(nums,v,i+1,subset,m) ; 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v = {}; 
        vector<int> subset ;
        map<vector<int>, int > m ;  
        sort(nums.begin(),nums.end()) ;
        helper(nums,v,0,subset ,m) ;
        return v; 
    }
};