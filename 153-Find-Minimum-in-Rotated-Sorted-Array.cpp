class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1 ; 
        int min  = 5000 ; 
        while(high >= low ){
            int mid = low + (high-low)/2 ; 
            if(nums[mid] < min) min = nums[mid] ; 
            if(nums[low] <= nums[mid]) {
                if(nums[low] < min)
               {
                 min = nums[low] ; 
               }
                low = mid + 1 ;  
            }
            else {
                high = mid - 1 ;
            }
        }
         return min ;
    }
};