class Solution {
public:
    vector<vector<int>> ans ; 
    void helper(int k , int n , int i ,vector<int>& temp ,int ele ){
        //Base Case 
        if(ele == k) {
          if(n == 0) {
            ans.push_back(temp) ;
          }
          return ;
        }
        if(i >= 9) return ; 
        if(n < 0) return ;


        //Logic
        temp.push_back(i+1);
        helper(k,n -i -1,i+1,temp,ele + 1);
        temp.pop_back() ; 
        helper(k,n,i+1,temp,ele);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp ; 
        helper(k,n,0,temp,0);
        return ans ;
    }
};