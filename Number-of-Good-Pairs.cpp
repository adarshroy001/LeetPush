class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> v(101,0) ;
        for(int i = 0 ; i < n ;++i ){
            v[nums[i]] ++ ; 
        }
        int sum = 0;
        for(int i = 0 ; i< v.size() ; ++i){
            if(v[i] != 0){
                int temp = v[i] ;
                sum += temp*(temp-1)/2 ; 
            }
        }
        return sum ;
    }
};