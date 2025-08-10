class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> pos;
        vector<int> neg; 
        for(int &it : nums){
            if(it >= 0){
                pos.push_back(it) ;
            }
            else{
                neg.push_back(it) ; 
            }
        } 
        int j = 0  , k = 0 ; 
        for(int i = 0 ; i< n ; i++) {
            if(i%2 == 0){
                nums[i] = pos[j] ; 
                j++;  
            }
            else{
                nums[i] = neg[k]; 
                k++ ;
            }
            
        }
        return nums ;
    }
};