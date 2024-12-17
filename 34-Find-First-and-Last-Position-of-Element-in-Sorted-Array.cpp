class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int low = 0 , high = n-1 , start = n , end = -1 ;
        // while(high>= low){
        //     int mid = low + (high-low)/2 ; 
        //     if(arr[mid] == target){
        //         start = mid ; 
        //     }
        //     if(arr[mid] < target){
        //         low = mid + 1 ;
        //     }
        // }
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == target){
               if(start > i) start = i ;
               if(end < i) end = i ;
            }
        }
         if(start == n) start = -1;
         return {start,end};
        
    }
};