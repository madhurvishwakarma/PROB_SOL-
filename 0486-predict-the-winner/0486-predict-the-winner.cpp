class Solution {
public:
    int f(int i, int j, vector<int>& nums , vector<vector<int>>& dp ) {
        if (i > j) return 0;
        if( dp[i][j] != -1 ) return dp[i][j] ;
        int pickLeft  = nums[i] - f(i+1, j, nums , dp);
        int pickRight = nums[j] - f(i, j-1, nums , dp);
        
        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp ( n ,vector<int>( n ,-1)) ;
        return f(0, n-1, nums , dp) >= 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna