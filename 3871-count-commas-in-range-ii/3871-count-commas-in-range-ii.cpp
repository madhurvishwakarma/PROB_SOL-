class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long threshold = 1000;

        while (threshold <= n) {
            count += (n - threshold + 1);
            if (threshold > n / 1000) break; 
            threshold *= 1000;
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna