class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() ;
        int l = 0 , r = n-1 , i = n-1 ;
        vector<int> v(n) ;
        while( l <= r ){
           if( nums[l]*nums[l] > nums[r]*nums[r] ){
            v[i] = nums[l]*nums[l] ;
            l++ ;
           }
           else{
            v[i] = nums[r]*nums[r] ;
            r-- ;
           }
           i-- ;
        }
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna