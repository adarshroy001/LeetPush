class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      map<int , int> sumMap ;
      sumMap[0] ++ ;
      int sum = 0 ; 
      int count = 0 ; 
      int n =  nums.size(); 
      for(int i = 0 ; i <n; i++){
        sum += nums[i] ;  
        int rem = sum - k ; 
        if(sumMap.find(rem) != sumMap.end()) {
            count += sumMap[rem]; 
        }
        sumMap[sum]++;
      } 
      return count ; 
    } 
};