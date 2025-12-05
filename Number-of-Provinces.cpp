1class Solution {
2private: 
3    void makeAdjList(vector<vector<int>>& isConnected , vector<vector<int>> &Listt , int n ){
4        for(int i = 0 ; i < n ; ++i){
5            for(int j = 0 ; j < n ; ++j){
6                if(isConnected[i][j] == 1 && i != j){
7                    Listt[i].push_back(j) ; 
8                    Listt[j].push_back(i) ; 
9                }
10            }
11        }
12    }  
13    void dfs (vector<vector<int>> &Listt , vector<int> &vis , int node){
14        vis[node] = 1 ;
15        for(auto it: Listt[node]){
16            if(!vis[it]){
17                dfs(Listt,vis,it) ; 
18            }
19        }
20    }  
21public:
22    int findCircleNum(vector<vector<int>>& isConnected) {
23        int count = 0 ; 
24        int n = isConnected.size() ;
25        vector<vector<int>> Listt(n);
26        makeAdjList(isConnected,Listt,n) ; 
27        vector<int> vis(n,0) ; 
28        for(int i = 0 ; i < n ; ++i){
29            if(!vis[i]){
30                count++ ; 
31                dfs(Listt , vis , i) ; 
32            }
33        }
34        return count ; 
35    }
36};