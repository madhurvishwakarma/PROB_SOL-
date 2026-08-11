class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long totalSum = 0, f0 = 0;
        
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            f0 += (long long)i * nums[i];
        }
        
        long long maxF = f0, prev = f0;
        for (int k = 1; k < n; k++) {
            long long curr = prev + totalSum - n * nums[n - k];
            maxF = max(maxF, curr);
            prev = curr;
        }
        
        return (int)maxF;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna