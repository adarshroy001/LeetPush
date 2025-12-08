1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int m =  mat.size() ; 
5        int n = mat[0].size() ; 
6        vector<vector<int>> vis(m,vector<int>(n,0)) ; 
7        vector<vector<int>> res(m,vector<int>(n,0)) ;
8        queue<pair<pair<int,int>,int>> q ;  
9        for(int i = 0 ; i < m ; ++i){
10            for(int j = 0 ; j < n ; ++j){
11               if(mat[i][j] == 0){
12                vis[i][j] = 1 ; 
13                q.push({{i,j},0}) ; 
14               } 
15            }
16        }
17        int dx[4] = {0,0,-1,1} ; 
18        int dy[4] = {-1,1,0,0} ; 
19        while(!q.empty()){
20            int x = q.front().first.first ; 
21            int y = q.front().first.second ; 
22            int dis = q.front().second ; 
23            q.pop()  ; 
24            res[x][y] = dis ; 
25            for(int i = 0 ; i<4 ;++i){
26                int nx = x + dx[i] ; 
27                int ny = y + dy[i] ; 
28                if(nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == 0) {
29                    vis[nx][ny] = 1 ; 
30                    q.push({{nx,ny},dis+1}) ; 
31                }
32            }
33        }
34        return res ; 
35    }
36};