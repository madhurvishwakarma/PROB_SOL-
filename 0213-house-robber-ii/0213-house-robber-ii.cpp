class Solution {
public:
    int calculate( vector<int>& nums , int start , int end ){
        int n = end - start +1 ;
        if( n < 0 ) return 0 ;
        if( n == 0 ) return nums[0] ;
        if( n == 1 ) return nums[start] ;
        vector<int> dp( n  ,-1 ) ;
        dp[0] = nums[start] ;
        for( int i=1 ; i<n ; i++ ){
            int take = nums[i+start] ;
            if( i > 1) take += dp[(i-2)%n] ;
            int Ntake = dp[i-1] ;
            dp[i] = max( take , Ntake ) ;
        }
        int sum = dp[n-1] ;
        return sum ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp( n  ,-1 ) ;
        return max( calculate(nums , 0, n-2 ) , calculate(nums,1,n-1) ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna