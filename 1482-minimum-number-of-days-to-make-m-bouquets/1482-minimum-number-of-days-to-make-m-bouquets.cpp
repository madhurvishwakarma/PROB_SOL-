class Solution {
public:
    bool possible( vector<int>& arr , int days , int m , int k ){
        long long  count = 0 ;
        long long  bouq = 0 ;
        long long  n = arr.size() ;
        for( long long  i =0 ; i<n ; i++ ){
            if( arr[i] <= days ){
                count ++ ;
            }
            else{
                bouq += count/k ;
                count = 0 ;
            }
        }
        bouq += count/k ;
        if( bouq >= m ){
            return true ;
        }
        return false ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size() ;
        if( n < 1LL*m*k ){
            return -1 ;
        }
        long long lo = *min_element( bloomDay.begin() , bloomDay.end() ) ;
        long long hi = *max_element( bloomDay.begin() , bloomDay.end() ) ;
        long long ans = 0 ;
        while( lo <= hi ){
            long long mid = lo + ( hi - lo )/2 ;
        if( possible( bloomDay , mid , m , k ) == true ){
            ans = mid ;
            hi = mid-1 ;
        }
        else{
            lo = mid+1 ;
        }
        }
    return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna