class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<long long> gains;
        for (int x : nums) {
            string s = to_string(x);
            sort(s.begin(), s.end(), greater<char>());
            sum += x;
            gains.push_back(stoll(s) - x);
        }
        sort(gains.begin(), gains.end(), greater<long long>());
        for (int i = 0; i < k; i++) sum += gains[i];
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna