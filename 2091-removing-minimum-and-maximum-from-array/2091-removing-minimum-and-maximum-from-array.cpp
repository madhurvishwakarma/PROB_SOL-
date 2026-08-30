class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mi = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mi]) mi = i;
            if (nums[i] > nums[mx]) mx = i;
        }
        if (mi > mx) swap(mi, mx);   // mi = leftmost of the two indices, mx = rightmost

        int frontOnly = mx + 1;               // delete a front prefix covering both
        int backOnly  = n - mi;               // delete a back suffix covering both
        int mixed     = (mi + 1) + (n - mx);  // front covers the left one, back covers the right one

        return min({frontOnly, backOnly, mixed});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna