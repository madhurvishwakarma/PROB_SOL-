class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;                     // all bits set
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {         // misplaced element
                k &= nums[i];
            }
        }
        return k == -1 ? 0 : k;         // -1 means already sorted
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna