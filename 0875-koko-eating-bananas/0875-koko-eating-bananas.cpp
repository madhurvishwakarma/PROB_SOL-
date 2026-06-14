class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // The idea of binary searching the eating speed is correct.
        // Time Complexity: O(N * log(maxPile)), where N = piles.size().
        // Space Complexity: O(1).
        // However, there are several issues:
        // 1. `lo` starts at 0, causing division by zero when `mid` becomes 0.
        //    It should start from 1.
        // 2. `sum` is not reset for each binary search iteration, so it accumulates
        //    across different `mid` values.
        // 3. The binary search loop condition should be `while (lo <= hi)`, not `lo <= h`.
        // 4. The condition `if (sum == h)` only handles exact matches. We need the
        //    smallest `mid` such that `sum <= h`. Adjust the logic:
        //    - If `sum > h`, increase speed (`lo = mid + 1`).
        //    - Else (`sum <= h`), record candidate and try lower speed
        //      (`ans = mid; hi = mid - 1`).
        // 5. Use integer arithmetic to compute hours per pile: `(x + mid - 1) / mid`
        //    instead of `ceil(x/mid)` to avoid floating point.
        // Apply these fixes to get a correct solution.
        int lo = 1, ans = INT_MAX ;
        int hi = *max_element( piles.begin() , piles.end() ) ;
        long long  sum = 0  ;
        while( lo <= hi ){
            int mid = lo + ( hi - lo )/2 ;
            sum =0 ; // imp 
            for( auto x : piles ){
                sum += ceil(double(x)/double(mid)) ;
            }
            if( sum <= h ){
                ans =mid ;
                hi = mid-1 ;
            }
            else{
                lo = mid+1 ;
            }
            
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna