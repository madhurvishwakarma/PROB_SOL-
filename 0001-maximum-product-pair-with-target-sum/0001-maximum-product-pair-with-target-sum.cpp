class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size() ;
        int first = 0 , second = 0 ;
        int multiple = INT_MIN ;
        for( int i=0 ; i<n ; i++ ){
            for( int j=0 ; j<n ; j++ ){
                if( nums[i] + nums[j] == target && nums[i] > nums[j] ){
                    if( nums[i]*nums[j] > multiple ){
                        multiple = nums[i]*nums[j] ;
                        first = i ;
                        second = j ;
                    }
                }
            }
        }
        if( multiple == INT_MIN ) return {-1,-1} ;
        return {first,second} ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna