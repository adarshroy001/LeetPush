1class Solution {
2    void dfs(vector<vector<char>>& board ,vector<vector<int>>& vis ,int i ,int j,int m ,int n){
3        vis[i][j] = 1 ; 
4        int dx[4] = {0,0,-1,1} ; 
5        int dy[4] = {-1,1,0,0} ; 
6        for(int k = 0 ; k < 4 ; ++k){
7            int nx = i + dx[k] ; 
8            int ny = j + dy[k] ; 
9            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] == 'O') {
10                dfs(board,vis,nx,ny,m,n) ; 
11            }
12         }
13    }
14public:
15    void solve(vector<vector<char>>& board) {
16        int m = board.size() ; 
17        int n = board[0].size() ; 
18        vector<vector<int>> vis(m,vector<int>(n,0)) ;
19        // in edges 
20            for(int j = 0 ; j < n ;++j){
21                if(board[0][j] == 'O' && !vis[0][j]){
22                    dfs(board,vis,0,j,m,n) ; 
23                }
24            }
25            for(int j = 0 ; j < n ;++j){
26                if(board[m-1][j] == 'O' && !vis[m-1][j]){
27                    dfs(board,vis,m-1,j,m,n) ; 
28                }
29            }
30            for(int j = 0 ; j < m ;++j){
31                if(board[j][0] == 'O' && !vis[j][0]){
32                    dfs(board,vis,j,0,m,n) ; 
33                }
34            }
35            for(int j = 0 ; j < m ;++j){
36                if(board[j][n-1] == 'O' && !vis[j][n-1]){
37                    dfs(board,vis,j,n-1,m,n) ; 
38                }
39            }
40
41
42        // except edges  (now since all the edge connected are visted and hence remaining all will be converted into x ) 
43        for(int i = 1 ; i < m ; ++i){
44            for(int j = 1 ; j < n ;++j){
45                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
46            }
47        }
48    }
49};