class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        long long best = LLONG_MAX;
        for (int i = 0; i < n; i += 2) {
            string temp = to_string(nums[i]) + to_string(nums[i + 1]);
            best = min(best, stoll(temp));
        }
        return best;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna