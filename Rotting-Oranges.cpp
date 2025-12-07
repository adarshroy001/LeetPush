1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int fresh = 0 ; 
5        int m = grid.size() ; 
6        int n = grid[0].size() ; 
7        queue<pair<int,pair<int,int>>> q ;
8        for(int i = 0 ; i < m ; ++i){
9            for(int j = 0 ; j < n ; ++j){
10                if(grid[i][j] == 2) q.push({0,{i,j}}) ; 
11                if(grid[i][j] == 1) fresh++ ; 
12            }
13        }
14        int count = 0 ;
15        int dx[4] = {0,0,-1,1} ; 
16        int dy[4] = {-1,1,0,0} ;  
17        while(!q.empty()){
18            int t = q.front().first ; 
19            int x = q.front().second.first; 
20            int y = q.front().second.second ; 
21            q.pop();
22            for(int i = 0; i<4; ++i ){
23                int nx = x + dx[i];
24                int ny = y + dy[i];
25                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 ){
26                    grid[nx][ny] = 2;
27                    q.push({t+1,{nx,ny}}); 
28                    count = max(count,t+1);
29                    fresh -- ; 
30                }
31            }
32        }
33        if(fresh > 0) return -1 ; 
34        return count;
35    }
36};