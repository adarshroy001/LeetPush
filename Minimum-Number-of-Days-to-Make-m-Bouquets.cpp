class Solution {
public:

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ; 
        int mini = INT_MAX ;
        int maxi = INT_MIN ;
        int finalres = INT_MAX ;
        if(1LL*m*k > n) return - 1 ; 
        for(int i = 0 ; i< n ; i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini , high = maxi  ; 
        while(high >= low){
            int mid = low + (high-low)/2 ; 
            int count = 0 , bcount = 0 ; 
            for(int j = 0 ; j<n ; j++){
                if(bloomDay[j]<= mid){
                    count += 1 ;  
                }
                else{
                    bcount = bcount + count/k ;  
                    count = 0 ; 
                }
            }
            // Final check after loop to count remaining flowers
            bcount += count / k;
            if(bcount >= m){
              finalres = min(finalres,mid) ;
              high = mid - 1 ;
            }
            else{
                low = mid + 1; 
            }  
        }
        return finalres ;
    }
};