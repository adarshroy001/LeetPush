class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
       int n =  piles.size() ; 
       int maxi = 0 ; 
       for(int i = 0 ; i < n ; i++){
        maxi = max(maxi, piles[i]) ; 
       }
       int low = 1 ,high = maxi; 
       int res = maxi ; 
       while(high >= low){
        int mid = low + (high-low)/2 ;
        int count = 0 ; 
        for(int i = 0; i< n ; i++){
            count += ceil((double)piles[i]/mid) ; 
            if(count > h) {
                low = mid+1 ; 
                break ; 
            }
        }
        if(count <= h ){
           res = min(res,mid);
           high = mid-1 ;  

        }

    }
    return res;

    }
};