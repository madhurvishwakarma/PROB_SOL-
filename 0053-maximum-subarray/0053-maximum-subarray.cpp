class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if( nums.size() == 0 ){
            return 0 ;
        }
        int sum = 0 ;
        int start = 0 , ansStart = 0 , ansEnd = 0 ;
        int maxi = INT_MIN ;
        for( int i =0 ; i< nums.size() ;i++ ){
            if( sum == 0 ){
                start = i ;
            }
            sum += nums[i] ;
            if( sum > maxi ){
                maxi = sum ;
                ansStart = start ;
                ansEnd = i ;
            }
            if( sum < 0 ){
                sum = 0 ;
            }
        }
        return maxi ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna