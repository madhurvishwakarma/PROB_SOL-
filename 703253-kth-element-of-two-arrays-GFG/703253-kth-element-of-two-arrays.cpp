class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size() ;
        int m = b.size() ;
        
        int lo = max( 0 , k-m ) ;
        int hi = min( k , n ) ;
        while( lo <= hi ){
            int mid1 = lo + ( hi - lo )/2 ;
            int mid2 = k - mid1 ;
            int l1 = INT_MIN , l2 = INT_MIN ;
            int r1 = INT_MAX , r2 = INT_MAX ;
            if( mid1 < n ) r1 = a[mid1] ;
            if( mid2 < m ) r2 = b[mid2];
            if( mid1-1 >= 0) l1 = a[mid1-1] ;
            if( mid2-1 >= 0) l2 = b[mid2-1] ;
            if( l1 <= r2 && l2 <= r1 ){
                return max(l1 , l2 ) ;
            }
            else if( l1 > r2 ){
                hi = mid1 -1 ;
            }
            else{
                lo = mid1+1 ;
            }
        }
        return 0 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna