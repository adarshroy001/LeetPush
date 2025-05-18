class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN ; 
        int ans = INT_MAX ;
        for(int i = 0 ; i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        int low = 1 ,high= maxi ; 
        while(high>=low){
           int mid = low + (high-low)/2 ;
           int sum = 0 ; 
           for(int i = 0 ; i< nums.size() ;i++){
            sum+= ceil((double)nums[i]/mid) ;
           }
           if(sum>threshold){
            low = mid + 1;
           }
           else{
            ans = min(ans,mid) ; 
            high = mid - 1; 
           }
        }
        return ans ; 
    }
};