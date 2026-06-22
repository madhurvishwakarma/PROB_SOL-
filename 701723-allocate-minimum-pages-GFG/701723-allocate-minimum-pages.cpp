class Solution {
  public:
    int allocate( vector<int>& v , int n ){
        int students = 1 ;
        int count = 0 ;
        for( int i =0 ; i< v.size() ; i++ ){
            if( count + v[i] <= n ){
                count += v[i] ;
            }
            else{
                students++ ;
                count = v[i] ;
            }
        }
        return students ;
    }
    int findPages(vector<int> &arr, int k) {
        if( k > arr.size() ){
            return -1 ;
        }
        int lo = *max_element(arr.begin() , arr.end() ) ;
        int hi = 0 ;
        for( auto x: arr ){
            hi += x ;
        }
        int ans = 0 ;
        while( lo <= hi ){
            int mid = lo + ( hi-lo )/2 ;
            int nums = allocate( arr , mid ) ;
            if( nums > k ){
                lo = mid+1 ;
            }
            else{
                ans = mid ;
                hi = mid-1 ;
            }
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna