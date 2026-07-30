class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp( n , 0 ) ;
        for( int i=0 ; i<m ; i++ ){
            vector<int> curr( n , 0 ) ;
            for( int j=0 ; j<n ; j++ ){
                if( i == 0 && j == 0 ){
                    curr[j] = 1 ;
                    continue ;
                }
                curr[j] = dp[j] ;
                if( j > 0) curr[j] += curr[j-1] ;
            }
            dp = curr ;
        }
        return dp[n-1] ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna