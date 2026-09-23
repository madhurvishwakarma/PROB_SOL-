#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        // ans[x] will store the total number of subarrays with product % k == x
        std::vector<long long> ans(k, 0);
        
        // dp[r] stores the count of subarrays ending at the previous index 
        // that have a product % k == r
        std::vector<long long> dp(k, 0);
        
        for (int num : nums) {
            std::vector<long long> newDp(k, 0);
            int numMod = num % k;
            
            // 1. Start a brand new subarray containing only the current element
            newDp[numMod] = 1;
            
            // 2. Extend all valid subarrays that ended at the previous element
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    int newMod = (i * numMod) % k;
                    newDp[newMod] += dp[i];
                }
            }
            
            // 3. Accumulate the current index's results into the final answer
            for (int i = 0; i < k; ++i) {
                ans[i] += newDp[i];
            }
            
            // Move to the next element
            dp = std::move(newDp);
        }
        
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna