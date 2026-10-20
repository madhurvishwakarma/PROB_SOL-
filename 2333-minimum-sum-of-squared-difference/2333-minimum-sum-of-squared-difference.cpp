class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        const int M = 100000;
        vector<long long> cnt(M + 1, 0);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            total += d;
        }
        if (total <= k) return 0;

        for (int v = M; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            long long take = min(cnt[v], k);
            cnt[v] -= take;
            cnt[v - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for (long long v = 1; v <= M; v++)
            ans += v * v * cnt[v];
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna