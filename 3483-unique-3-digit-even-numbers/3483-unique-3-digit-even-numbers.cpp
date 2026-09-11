class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;          // no leading zero
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 != 0) continue;   // must be even

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    nums.insert(num);
                }
            }
        }
        return nums.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna