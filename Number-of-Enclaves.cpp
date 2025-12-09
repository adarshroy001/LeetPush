1class Solution {
2    void dfs(vector<vector<int>>& res , int i , int j , int m , int n){
3        res[i][j] = 0 ; 
4        int dx[4] = {0,0,-1,1} ; 
5        int dy[4] = {-1,1,0,0} ;
6        for(int k = 0 ; k < 4 ; ++k){
7            int nx = i + dx[k] ; 
8            int ny = j + dy[k] ;
9            if(nx >= 0 && nx < m && ny >= 0 && ny < n && res[nx][ny]){
10                dfs(res,nx,ny,m,n) ;
11            }
12        }
13    }
14public:
15    int numEnclaves(vector<vector<int>>& grid) {
16        int m = grid.size() ; 
17        int n = grid[0].size() ; 
18        vector<vector<int>> res = grid ; 
19        for(int i = 0 ; i < n ; ++i ){
20            if(res[0][i] == 1) dfs(res,0,i,m,n) ; if(res[m-1][i] == 1) dfs(res,m-1,i,m,n) ;
21        }
22        for(int i = 0 ; i < m ; ++i ){
23            if(res[i][0] == 1) dfs(res,i,0,m,n) ; if(res[i][n-1] == 1) dfs(res,i,n-1,m,n) ;
24        }
25        int count = 0 ; 
26        for(int i = 0 ; i < m ; ++i){
27            for(int j = 0 ; j < n ; ++j){
28                if(res[i][j] == 1) count++ ;
29            }
30        }
31        return count ; 
32     }
33};