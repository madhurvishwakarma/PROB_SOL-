class Solution {
  public:
    bool possible( vector<int>& arr , int gap , int k ){
        int cows = 1 ;
        int first = arr[0] ;
        for( int i =1 ; i<arr.size() ; i++ ){
            if( arr[i] - first >= gap ){
                cows++ ;
            first = arr[i] ;
            }
        }
        if( cows < k ){
            return false ;
        }
        return true ;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort( stalls.begin() , stalls.end()) ;
        int n = stalls.size() ;
        int ans = 0 ;
        int lo = 0 , hi = stalls[n-1] ;
        while( lo <= hi ){
            int mid = lo + ( hi-lo )/2 ;
            if( possible( stalls , mid , k ) == true ){
                ans = mid ;
                lo = mid+1 ;
            }
            else{
                hi = mid-1 ;
            }
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna