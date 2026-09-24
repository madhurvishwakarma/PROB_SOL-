class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size() ;
        int ans = INT_MAX ;
        for( int i=0 ; i<n ; i++ ){
            int count = 0 ;
            while( nums[i] != 0 ){
                count += nums[i]%10 ;
                nums[i] = nums[i]/10 ;
            }
            if( count == i ) ans = min( count , ans ) ;
        }
        if( ans == INT_MAX ) return -1 ;
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna