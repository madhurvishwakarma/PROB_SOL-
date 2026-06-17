// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1 ;
        int hi = n ;
        int ans = 0 ;
        while( lo <= hi ){
            int mid = lo + ( hi - lo )/2 ;
            if( isBadVersion(mid) == true ){
                ans =  mid ;
                hi = mid-1 ;
            }
            else if( isBadVersion(mid) == false ){
                lo = mid+1 ;
            }
        }
        return ans  ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna