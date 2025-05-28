class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = INT_MIN ; 
        int maxi = 0 ; 
        for(int &weight: weights ){
            mini = max(mini,weight) ; 
            maxi += weight ;
        }
        int low = mini , high = maxi ; 
        while (high>=low){
            int mid = low + (high -low)/2 ;
            int dayCount = 0 ; 
            long long sum = 0 ; 

            for(int j = 0 ; j< weights.size() ; j++){
              
              if(weights[j] + sum <= mid){
                sum+=weights[j] ; 
              } 
              else{
                dayCount++ ; 
                sum = weights[j] ; 
              }
            }
            
            if(dayCount + 1 <= days) {
                high = mid-1 ; 
            }
            else {
                low = mid+1  ;
            }
        }
        return low ; 
        
    }
};