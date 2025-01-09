class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1 ; 
        int minm  = 5000 ; 
        while(high >= low ){
            int mid = low + (high-low)/2 ; 
            if(nums[mid] < minm) minm = nums[mid] ; 
            if(nums[low] <= nums[mid]) {
                 minm = min(minm,nums[low]) ; 
                low = mid + 1 ;  
            }
            else {
                high = mid - 1 ;
            }
        }
         return minm ;
    }
};