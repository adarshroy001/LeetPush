class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int j = 0 ;
        int len = strs[0].size();
        while(j < len ){
         char ch = strs[0][j] ;
         bool isCommon = true ;
         for(int i = 1 ; i < strs.size() ; i++){
            if(j < strs[i].size()){
                if(strs[i][j] != ch) {
                  return ans;
                }
            } else{
                isCommon = false ;
            }
         }
         if(isCommon){
            ans.push_back(ch) ; 
         }
         j++;
        }
        return ans;
    }
};