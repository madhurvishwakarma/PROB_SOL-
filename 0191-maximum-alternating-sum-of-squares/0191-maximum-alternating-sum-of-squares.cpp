class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ;
        long long sum = 0 ;
        vector<long long> ans(n,0) ;
        for( int i=0 ; i<n ; i++ ){
            ans[i] = 1LL*nums[i]*nums[i] ;
        }
        sort( ans.begin() , ans.end() ) ;
        for( int i=0 ; i<n/2 ; i++ ){
            sum -= ans[i] ;
        }
        for (int i = n / 2; i < n; i++) sum += ans[i];
        return sum ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna