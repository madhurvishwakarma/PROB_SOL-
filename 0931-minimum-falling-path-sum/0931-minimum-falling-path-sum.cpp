class Solution {
public:
    int f( int i  , int j , vector<vector<int>>& matrix , vector<vector<int>>& dp ){
        int n = matrix.size() ;
        if( i == 0 ) return matrix[i][j] ;
        if( dp[i][j] != INT_MIN ) return dp[i][j] ;
        int left = matrix[i][j] ;
        if( i > 0 && j > 0) left += f( i-1 , j-1 , matrix , dp ) ;
        else left = INT_MAX;
        int mid = matrix[i][j] ;
        if( i > 0 ) mid += f( i-1 , j , matrix , dp ) ;
        int right = matrix[i][j] ;
        if( i > 0  && j < n-1 ) right += f( i-1 , j+1 , matrix , dp ) ;
        else right = INT_MAX;                      
        return dp[i][j] = min({ left , mid , right }) ;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int result = INT_MAX;
        vector<vector<int>> dp( n, vector<int>( n, INT_MIN)) ;
for (int j = 0; j < n; j++) {
    result = min(result, f(n-1, j, matrix , dp));
}
        return result ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna