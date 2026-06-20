class Solution {
public:
    bool possible( vector<int>& arr , int gap , int m ){
        int n = arr.size() ;
        int count = 1 ;
        int first = arr[0] ;
        for( int i = 1 ; i< n ; i++ ){
            if( arr[i] - first >= gap ){
                count++ ;
                first = arr[i] ;
            }
        }
        if( count < m ){
            return false ;
        }
        return true ;
    }
    int maxDistance(vector<int>& position, int m) {
        sort( position.begin() , position.end() ) ;
        int n = position.size() ;
        int lo = 0 , hi = position[n-1] ;
        int ans = 0 ; 
        while( lo <= hi ){
            int mid = lo + ( hi -lo )/2 ;
            if( possible(position , mid , m ) == true ){
                ans = mid ;
                lo = mid +1 ;
            }
            else{
                hi = mid -1 ;
            }
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna