class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Time Complexity: O(log n) using binary search.
        // Space Complexity: O(1) auxiliary space.
        int n = nums.size() ;
        if( n == 1 ){
            // BUG: Should return index 0 (the position), not the value.
            // Hint: replace `return nums[0];` with `return 0;`
            return 0 ;
        }
        if( nums[0] > nums[1] ){
            // BUG: Returning the value; should return index 0.
            // Hint: replace `return nums[0];` with `return 0;`
            return 0 ;
        }
        if( nums[n-1] > nums[n-2] ){
            // BUG: Returning the value; should return index n-1.
            // Hint: replace `return nums[n-1];` with `return n-1;`
            return n-1 ;
        } 
        int lo = 1  , hi = n-2 ;
        while( lo <= hi ){
            int mid = lo + ( hi-lo )/2 ;
            if( (nums[mid] > nums[mid-1]) && (nums[mid] > nums[mid+1]) ){
                // Found a peak at mid, return its index.
                return mid ;
            }
            else if( nums[mid] > nums[mid-1] ){
                // Since nums[mid] > nums[mid-1] but not > nums[mid+1],
                // the peak must be to the right.
                lo = mid+1 ;
            }
            else{
                // nums[mid] <= nums[mid-1], so move left.
                hi = mid-1 ;
            }
        }
        // The problem guarantees at least one peak, so this line should never be reached.
        return -1 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna