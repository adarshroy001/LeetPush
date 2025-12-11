1class Solution {
2private: 
3    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,stack<int>& s,vector<int>& pathvis ){
4        vis[i] = 1;  pathvis[i] = 1; 
5        for(auto it: adj[i]){
6            if(!vis[it]){
7                if(dfs(it,adj,vis,s,pathvis)) return true ;  
8            }
9            else{
10                if(pathvis[it]) return true ;
11            }
12        }
13        pathvis[i] = 0 ; 
14        s.push(i) ; 
15        return false ; 
16    }    
17public:
18    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
19        int n = numCourses ; 
20        vector<vector<int>> p = prerequisites ; 
21        //making adjancacy list 
22        vector<vector<int>> adj(n) ; 
23        for(int i = 0 ; i < p.size() ; ++i){
24            int u = p[i][0] , v = p[i][1] ; 
25            adj[v].push_back(u) ; 
26        }
27
28        //topo short using dfs 
29        vector<int> vis(n,0) ,pathvis(n,0), res; 
30        stack<int> s ;
31        for(int i = 0 ; i < n ; ++i){
32            if(!vis[i]){
33                if(dfs(i,adj,vis,s,pathvis)) return {} ; 
34            }
35        }
36
37        // emptying stack 
38        while (!s.empty()) {
39            res.push_back(s.top());
40            s.pop();
41        }
42
43
44        // failed on testcase numCourses = 2 and prerequisites = [[0,1],[1,0]] o/p = []
45        // so we have to take care of cyclic too => if cyclic then return empty vector
46        return res ; 
47    }
48};