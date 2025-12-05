1//Method-1 By changing Matrix into List and doing dfs 
2//TC-  Sc- 
3// class Solution {
4// private: 
5//     void makeAdjList(vector<vector<int>>& isConnected , vector<vector<int>> &Listt , int n ){
6//         for(int i = 0 ; i < n ; ++i){
7//             for(int j = 0 ; j < n ; ++j){
8//                 if(isConnected[i][j] == 1 && i != j){
9//                     Listt[i].push_back(j) ; 
10//                     Listt[j].push_back(i) ; 
11//                 }
12//             }
13//         }
14//     }  
15//     void dfs (vector<vector<int>> &Listt , vector<int> &vis , int node){
16//         vis[node] = 1 ;
17//         for(auto it: Listt[node]){
18//             if(!vis[it]){
19//                 dfs(Listt,vis,it) ; 
20//             }
21//         }
22//     }  
23// public:
24//     int findCircleNum(vector<vector<int>>& isConnected) {
25//         int count = 0 ; 
26//         int n = isConnected.size() ;
27//         vector<vector<int>> Listt(n);
28//         makeAdjList(isConnected,Listt,n) ; 
29//         vector<int> vis(n,0) ; 
30//         for(int i = 0 ; i < n ; ++i){
31//             if(!vis[i]){
32//                 count++ ; 
33//                 dfs(Listt , vis , i) ; 
34//             }
35//         }
36//         return count ; 
37//     }
38// };
39
40
41
42class Solution {
43private:
44    void dfs(vector<vector<int>>& isConnected , vector<int> &vis , int node , int n){
45        vis[node] = 1 ;
46        for(int j = 0 ; j < n ; ++j){
47            if(!vis[j] && isConnected[node][j]){
48                dfs(isConnected , vis , j , n) ; 
49            }
50        }
51    }
52public:
53    int findCircleNum(vector<vector<int>>& isConnected) {
54        int count = 0 ; 
55        int n = isConnected.size() ; 
56        vector<int> vis(n,0) ;
57        for(int i = 0 ; i < n ; ++i){
58            if(!vis[i]){
59              count ++ ;   
60             dfs(isConnected , vis , i , n) ;
61            }
62        }
63      return count ; 
64    }
65};