class Solution {
public:
    int bfs( int r , int c , vector<vector<int>>& grid , vector<vector<int>>& vis ){
        vis[r][c] = 1 ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<int,int>> q ;
        q.push({ r ,c }) ;
        int dr[] = {-1,1,0,0} ;
        int dc[] = {0,0,-1,1} ;
        int area = 1 ;
        while( !q.empty() ){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            for( int i =0 ; i<4 ; i++ ){
                int nr = row + dr[i] ;
                int nc = col + dc[i] ;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    area++ ;
                }
            }
        }
        return area ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis( n , vector<int>( m, 0)) ;
        int area = 0 ;
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    area = max(area , bfs(i, j, grid, vis));
                }
            }
        }
        return area ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna