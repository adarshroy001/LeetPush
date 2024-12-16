class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int low = 0 , high = n-1 ;
        int res = INT_MIN ,resind = - 1 ;
        while(high >= low){
            int mid = (low+high)/2 ;
            if(nums[mid]==target){
                return mid ; 
            }
            else if (nums[mid] < target && res < nums[mid] ){
                res = nums[mid] ; 
                resind = mid ;
                low = mid + 1 ;
            }
            else {
                high = mid -1 ;
            }
        }
        return resind+1 ; 
    }
};