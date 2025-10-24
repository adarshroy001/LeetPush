class Solution {
public:
    string reverseWords(string s) {
        string ans = "" ; 
        vector<string> v ; 
        string temp = "" ;
        bool issomething = false ;
        for(auto &it: s){
            if(it != ' '){
                temp += it ; 
                issomething = true ; 
            }
            if(it == ' ' && issomething){
                v.push_back(temp) ; 
                temp = "" ;
                issomething = false ; 
            }
        }
        string temp2 ="" ;
        for(auto &it: temp){
            if(it != ' '){
                temp2 += it ; 
            }
            else{
                v.push_back(temp2) ; 
            }
        }
        if(temp.length() != 0) v.push_back(temp) ; 
        int n = v.size() ; 
        for(int i = n-1 ; i >= 0 ;--i){
                ans += v[i] ; 
                if(i != 0){
                ans += " " ; 
            }
        }
        return ans ; 
    }
};