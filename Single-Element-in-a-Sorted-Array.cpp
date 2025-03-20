class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1 ) return nums[0] ; 
        if (nums[0] != nums[1]) return nums[0] ; 
        if(nums[nums.size()-1] !=nums[nums.size()-2]) return nums[nums.size()-1];
        int high = nums.size()-2 , low = 1 ; 
        while (high >= low ){
            int mid = low + (high-low)/2 ;
             //if arr[mid] is the single element:
             if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                 return nums[mid];
              } 
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) 
                    low = mid+1;
                else 
                    high = mid-1;
            } else {
                if (nums[mid] == nums[mid - 1]) 
                    low = mid+1;
                else 
                    high = mid-1;
            }

        }
        return - 1 ;
    }
};