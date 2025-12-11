1class Solution {
2public:
3    bool dfs(int i , vector<vector<int>> &list , vector<int>& vis , vector<int>& pathvis){
4        vis[i] = 1 ; 
5        pathvis[i] = 1 ; 
6        for(int it : list[i]){
7            if(!vis[it]){
8                if( dfs(it,list,vis,pathvis)) return true ; 
9            }
10            else{
11                if(pathvis[it]) return true ; 
12            }
13        }
14        pathvis[i] = 0 ; 
15        return false ;
16    }
17    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
18        int n = numCourses ;
19        //numcourses is vertex  
20        // prerequisites is more or less edges 
21        //M-1 using dfs
22        //if it is cyclic then return false 
23        vector<int> vis(n,0) ,pathvis(n,0); 
24        //we dont have adjacency list so make one 
25        vector<vector<int>> list(n) ; 
26        for(int i = 0 ; i < prerequisites.size() ; ++i){
27            int u = prerequisites[i][0] , v = prerequisites[i][1] ;
28            list[v].push_back(u);
29        }
30        for(int i = 0 ; i < n ; ++i){
31            if(!vis[i]){
32                if(dfs(i,list,vis,pathvis)) return false ; 
33            }
34        }
35        return true ; 
36    }
37};