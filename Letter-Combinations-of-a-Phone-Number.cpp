// class Solution {
// public:
//     unordered_map<char, string> mp = {
//     {'2', "abc"},
//     {'3', "def"},
//     {'4', "ghi"},
//     {'5', "jkl"},
//     {'6', "mno"},
//     {'7', "pqrs"},
//     {'8', "tuv"},
//     {'9', "wxyz"}
//    };
//     vector<string> ans ;
//     void helper(string digits , int index){
//           if(index < 0) return ; 
//            char ch = digits[index] ; 
//            string s = mp[ch] ; 
//            vector<string> temp  ;
//            for(int i = 0  ; i < s.length() ; ++i){
//              if(ans.size() == 0 ){
//                 char comb = s[i]; 
//                 string temp2 = "" ; 
//                 temp2 += s[i] ;
//                 temp.push_back(temp2) ;
//              }else{
//                 for(int j = 0 ; j < ans.size();++j){
//                 string comb = s[i] + ans[j] ;
//                 temp.push_back(comb) ; 
//              }
//              }
//            }
//            ans = temp ; 
//            helper(digits,index - 1) ; 
//     } 
//     vector<string> letterCombinations(string digits) {
//         helper(digits,digits.size()-1) ; 
//         return ans ;
//     }
// };


//M-2 more optimised 
class Solution {
public:
    unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
   };
    vector<string> ans ;
    void helper(string digits , int index , string &temp){
         if(index == digits.size()){
            ans.push_back(temp) ;
            return ;
         }

        string str = mp[digits[index]] ;
        for(int i = 0 ; i < str.size() ; i++){
            temp.push_back(str[i]) ;
            helper(digits,index+1,temp) ;
            temp.pop_back() ;
        }
    } 
    vector<string> letterCombinations(string digits) {
        string s ; 
        helper(digits,0,s) ; 
        return ans ;
    }
};