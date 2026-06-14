class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index = 0 , ans = INT_MIN ;
        int n = nums.size() ;
        for( int i =0 ;  i < n ; i++ ){
            if( ans <= nums[i] ){
                ans = nums[i] ;
                index = i ;
            }
        }
        return index ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna