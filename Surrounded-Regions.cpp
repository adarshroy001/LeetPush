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
14    void dfsx(vector<vector<char>>& board ,vector<vector<int>>& vis ,int i ,int j,int m ,int n){
15        vis[i][j] = 1 ; 
16        board[i][j] = 'X' ; 
17        int dx[4] = {0,0,-1,1} ; 
18        int dy[4] = {-1,1,0,0} ; 
19        for(int k = 0 ; k < 4 ; ++k){
20            int nx = i + dx[k] ; 
21            int ny = j + dy[k] ; 
22            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] == 'O') {
23                dfsx(board,vis,nx,ny,m,n) ; 
24            }
25         }
26    }
27public:
28    void solve(vector<vector<char>>& board) {
29        int m = board.size() ; 
30        int n = board[0].size() ; 
31        vector<vector<int>> vis(m,vector<int>(n,0)) ;
32        // in edges 
33            for(int j = 0 ; j < n ;++j){
34                if(board[0][j] == 'O' && !vis[0][j]){
35                    dfs(board,vis,0,j,m,n) ; 
36                }
37            }
38            for(int j = 0 ; j < n ;++j){
39                if(board[m-1][j] == 'O' && !vis[m-1][j]){
40                    dfs(board,vis,m-1,j,m,n) ; 
41                }
42            }
43            for(int j = 0 ; j < m ;++j){
44                if(board[j][0] == 'O' && !vis[j][0]){
45                    dfs(board,vis,j,0,m,n) ; 
46                }
47            }
48            for(int j = 0 ; j < m ;++j){
49                if(board[j][n-1] == 'O' && !vis[j][n-1]){
50                    dfs(board,vis,j,n-1,m,n) ; 
51                }
52            }
53
54
55        // except edges  
56        for(int i = 1 ; i < m ; ++i){
57            for(int j = 1 ; j < n ;++j){
58                if(board[i][j] == 'O' && !vis[i][j]){
59                    dfsx(board,vis,i,j,m,n) ; 
60                }
61            }
62        }
63    }
64};