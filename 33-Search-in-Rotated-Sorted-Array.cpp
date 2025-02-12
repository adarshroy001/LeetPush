class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()  ;
        int index = - 1 ; 
        int low = 0 , high =  n - 1 ;
        while(high>=low){
            int mid = low + (high-low)/2 ;
            if(nums[mid]==target) return mid ;
            if( nums[low] <= nums[mid]){
                  if(nums[low] <= target && target < nums[mid] ){
                    high = mid- 1 ;
                  }
                  else{
                  low = mid + 1 ;
                  }
            }
            else{
                  if(nums[high]>=target && target > nums[mid] ){
                    low = mid + 1; 
                  }
                  else{
                    high = mid - 1; 
                  }
            }
        }

        
        return -1 ;
    }
};