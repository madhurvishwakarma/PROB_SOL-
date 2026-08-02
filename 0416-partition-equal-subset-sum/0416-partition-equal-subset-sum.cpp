class Solution {
public:
    bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == 0) return nums[0] == target;
        if (dp[i][target] != -1) return dp[i][target];

        bool ntake = f(i-1, target, nums, dp);
        bool take = false;
        if (target >= nums[i]) take = f(i-1, target - nums[i], nums, dp);

        return dp[i][target] = (ntake || take);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 == 1) return false;

        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return f(n-1, sum/2, nums, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna