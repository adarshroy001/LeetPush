class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1,m2 ; 
        int len1 = s.size() , len2 = t.size(); 
        if(len1 != len2) return false ; 
        for(int i = 0 ; i < len1 ; i++){ 
            char chs = s[i]  , cht = t[i] ; 
            if(m1.count(chs) && m1[chs] != cht) return false ;
            if(m2.count(cht) && m2[cht] != chs) return false ; 
            m1[chs] = cht ; 
            m2[cht] = chs ; 
        }
        return true ; 
    }
};

//Note -> s = "ab", t = "aa"
//Take care of this kind of test case too here if b is replece with a it will be same 
