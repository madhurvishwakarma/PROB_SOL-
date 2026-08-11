class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int i = 1;
        while (i < n && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }
        unordered_set<int> present(nums.begin(), nums.end());
        int candidate = sum;
        while (present.find(candidate) != present.end()) {
            candidate++;
        }
        
        return candidate;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna