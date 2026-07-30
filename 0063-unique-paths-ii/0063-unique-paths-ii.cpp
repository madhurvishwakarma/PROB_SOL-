class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() ;
        int m = obstacleGrid[0].size() ;
        if( n == 1 && m == 1 && obstacleGrid[n-1][m-1] == 1 ) return 0 ;
        if( obstacleGrid[0][0] == 1 ) return 0 ;
        vector<int> dp(m ,0) ;
        for( int i=0 ; i<n ; i++ ){
            vector<int> curr( m , 0);
            for( int j=0 ; j<m ; j++ ){
                if( i == 0 && j == 0 ){
                    curr[j] = 1 ;
                    continue ;
                }
                if( obstacleGrid[i][j] == 1 ){
                    curr[j] = 0 ;
                    continue ;
                }
                curr[j] = dp[j] ;
                if( j > 0 ) curr[j] += curr[j-1] ;
            }
            dp = curr ;
        }
        return dp[m-1] ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna