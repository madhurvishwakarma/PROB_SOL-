class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dummy(heights) ;
        int count = 0 ;
        sort(dummy.begin() , dummy.end()) ;
        int n = dummy.size() ;
        for( int i=0 ; i<n ; i++ ){
            if( heights[i] != dummy[i] ) count++ ;
        }
        return count ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna