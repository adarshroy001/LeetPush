class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int low = 0 , high = n-1 , start = n , end = -1 ;
        //finding first occurence 
        while(high>= low){
            int mid = low + (high-low)/2 ; 
            if(nums[mid] < target){
                low = mid + 1 ;
            }
            else {
                if(start > mid && nums[mid]==target) {start = mid ;}
                high = mid -1 ;
            }
        }
        //finding last occurence 
        low = 0 ;
        high = n-1;
        while(high>= low){
            int mid = low + (high-low)/2 ; 
            if(nums[mid] <= target){
               low = mid + 1 ;
              if(end < mid  && nums[mid]==target ){ end = mid ;}
            }
            else {
                high = mid -1 ;
            }
        }
     
         if(start == n) start = -1;
         return {start,end};
        
    }
};