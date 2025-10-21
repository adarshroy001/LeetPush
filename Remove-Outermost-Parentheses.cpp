class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "" ; 
        int count =   0 ; 
        for(auto it: s){
           if(count == 0 && it == '('){
            count ++ ; 
           }
           else if(count == 1 && it == ')'){
            count -- ; 
           }else{
            ans += it ; 
            if(it == '(') count ++ ; 
            else count -- ; 
           }
        } 
        return ans ; 
    }
};