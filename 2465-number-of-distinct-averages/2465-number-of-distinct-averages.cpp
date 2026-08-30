class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<double> averages;
        int l = 0, r = n - 1;
        while (l < r) {
            double avg = (nums[l] + nums[r]) / 2.0;
            averages.insert(avg);
            l++;
            r--;
        }
        return averages.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna