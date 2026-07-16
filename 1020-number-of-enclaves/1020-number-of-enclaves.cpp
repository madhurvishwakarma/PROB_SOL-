class Solution {
public:
    void dfs( int row , int col , vector<vector<int>>& vis , vector<vector<int>>& mat ){
        int n = mat.size() ;
        int m = mat[0].size() ;
        int dr[] = { -1,1,0,0} ;
        int dc[] = {0,0,-1,1 } ;
        vis[row][col] = 1 ;
        for( int i =0 ; i< 4 ;i++ ){
            int nr = row + dr[i] ;
            int nc = col + dc[i] ;
            if( nr < n && nr >= 0 && nc < m && nc >= 0 && vis[nr][nc] == 0 && mat[nr][nc] == 1){
                dfs(nr,nc,vis,mat) ;
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis( n , vector<int> ( m, 0 )) ;
        for( int i =0 ; i < n ; i++ ){
            if( vis[i][0] == 0 && grid[i][0] == 1 ){
                dfs( i , 0 , vis , grid ) ;
            }
            if( vis[i][m-1] == 0 && grid[i][m-1] == 1 ){
                dfs( i , m-1, vis , grid) ;
            }
        }
         for( int i =0 ; i < m ; i++ ){
            if( vis[0][i] == 0 && grid[0][i] == 1 ){
                dfs( 0 , i , vis , grid ) ;
            }
            if( vis[n-1][i] == 0 && grid[n-1][i] == 1 ){
                dfs( n-1 , i, vis , grid) ;
            }
        }
        int count = 0 ;
        for( int i = 0 ; i< n ; i++ ){
            for( int j =0 ; j < m ; j++ ){
                if( vis[i][j] == 0 && grid[i][j] == 1 ){
                    vis[i][j] = 1 ;
                    count++ ;
                }
            }
        }
        return count ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna