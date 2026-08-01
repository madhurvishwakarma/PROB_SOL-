class Solution {
public:
    int f(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        //if (i == j) return nums[i];
        
        int pickLeft  = nums[i] - f(i+1, j, nums);
        int pickRight = nums[j] - f(i, j-1, nums);
        
        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return f(0, n-1, nums) >= 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna