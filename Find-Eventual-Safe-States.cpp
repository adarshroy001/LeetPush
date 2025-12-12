1class Solution {
2public:
3    bool iscyclic(vector<vector<int>>& graph,int i , vector<int>& vis ,vector<int>& pathvis,
4    vector<int>& res){
5        vis[i] = 1;
6        pathvis[i] = 1;
7        // res[i] = 0;
8        for(auto it: graph[i]){
9            if(!vis[it]){
10                if(iscyclic(graph,it,vis,pathvis,res)){
11                    return true ; 
12                } 
13            }
14            else if(pathvis[it]) {
15                return true ;
16            } 
17        }
18        pathvis[i] = 0 ; 
19        res[i] = 1;
20        return false ; 
21    }
22    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
23      int n = graph.size();  
24      vector<int> vis(n,0) , pathvis(n,0) ,res(n,0) , ans; 
25      for(int i = 0 ; i < n ; ++i){
26        if(!vis[i]){
27            iscyclic(graph,i,vis,pathvis,res); 
28        }
29      }
30      for(int i = 0 ; i < n ; ++i){
31        if(res[i]){
32         ans.push_back(i);
33        }
34      }
35      return ans;
36    }
37};