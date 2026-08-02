class Solution {
public:
    int f( int start , int end , vector<int>& piles , vector<vector<int>>& dp ){
        if( start > end ) return 0 ;
        if( dp[start][end] != INT_MIN ) return dp[start][end] ;
        int left = piles[start] - f( start+1 , end , piles , dp ) ;
        int right = piles[start] - f( start , end-1 , piles ,dp  ) ;
        return dp[start][end] = max( left , right ) ;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size() ;
        vector<vector<int>> dp( n , vector<int>( n , INT_MIN )) ;
        return f( 0, n-1 , piles , dp ) >= 0 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna