class Solution {
public:
    int calculate( vector<int>& nums ){
        int n = nums.size() ;
        if( n < 0 ) return 0 ;
        vector<int> dp ( n , -1 ) ;
        dp[0] = nums[0] ;
        for( int i=1  ; i<n ; i++ ){
            int take = nums[i] ;
            if( i > 1 ) take += dp[i-2] ;
            int Ntake = dp[i-1] ;
            dp[i] = max( take , Ntake ) ;
        }
        return dp[n-1] ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if( n == 1 ) return nums[0] ;
        vector<int> v1 , v2 ;
        for( int i=0 ; i<n ; i++ ){
            if( i != 0 ) v1.push_back(nums[i]) ;
            if( i != n-1 ) v2.push_back( nums[i]) ;
        }
        return max( calculate(v1) , calculate(v2)) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna