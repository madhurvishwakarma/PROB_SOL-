class Solution {
    const long long MOD = 1e9 + 7;
    vector<long long> sum, sq, lz;

    void apply(int node, int len, long long k) {
        sq[node] = (sq[node] + 2 * k % MOD * sum[node] + k * k % MOD * len) % MOD;
        sum[node] = (sum[node] + k * len) % MOD;
        lz[node] += k;
    }

    void push(int node, int l, int r) {
        if (lz[node] == 0) return;
        int mid = (l + r) / 2;
        apply(2 * node, mid - l + 1, lz[node]);
        apply(2 * node + 1, r - mid, lz[node]);
        lz[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sq[node] = (sq[2 * node] + sq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);
            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna