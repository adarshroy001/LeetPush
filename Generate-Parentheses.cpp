class Solution {
public:
    void helper(vector<string> &v ,int o , int c ,string &s) {
        //Base case
        if(o == 0 & c == 0){
            v.push_back(s) ;
            return ;
        }
        //Main logic
        if(o>0){
            s.push_back('(') ;
            helper(v,o-1,c,s) ;
            s.pop_back() ;
        } 
        if(c>0 && c > o){
            s.push_back(')') ;
            helper(v,o,c-1,s) ;
            s.pop_back() ;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v ; 
        string s = "" ; 
        helper(v,n,n,s) ;
        return v ;
    }
};