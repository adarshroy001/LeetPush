class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN ; 
        int mini = prices[0] ;
         for(int i = 0 ; i < prices.size() ; i++){
            maxProfit = max(prices[i]-mini , maxProfit) ; 
            mini = min(mini,prices[i]) ; 
         }
         return maxProfit ;
    }
};