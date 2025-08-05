class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // idea is simple if a element while occur greater than n/2 times in an array 
        // that means count of other element combinedly will be lesser than that element 
        int count , ele = 0 ; 
        int n = nums.size() ;

        for(int i = 0 ; i< n ; i++){
            if(count == 0){
                ele = nums[i] ; 
                count++ ; 
            }
            else if (nums[i] == ele) count++ ; 
            else count -- ; 
        }
        int count2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == ele) count2++ ;
        } 
        if(count2 > n/2) return ele ; 
        return -1 ; 
    }
};