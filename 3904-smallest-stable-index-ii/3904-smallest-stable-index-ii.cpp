class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> mini ;
        vector<int> maxi ;
        int temp = -1 ;
        for( int i=0 ; i<n ; i++ ){
            temp = max( temp , nums[i] ) ;
            maxi.push_back(temp) ;
        }
        temp = 1e9 ;
        for( int i=n-1;i>= 0 ;i--){
            temp = min( temp , nums[i] ) ;
            mini.push_back(temp) ;
        }
        reverse(mini.begin(), mini.end()); 
         for (int i = 0; i < n; i++) {
            if (maxi[i] - mini[i] <= k) {  
                return i;                 
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna