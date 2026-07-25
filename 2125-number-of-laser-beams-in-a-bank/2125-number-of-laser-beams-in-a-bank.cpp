class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int n = bank.size() ;
       vector<int> v ;
       for( int i=0 ;i< n ;i++ ){
        int count = 0 ;
        for( auto x : bank[i]){
            if( x == '1'){
                count++ ;
            }
        }  
        if( count >0 ) v.push_back(count) ;
       }
       int sum = 0 ;
       int m = v.size() ;
       if( m == 1) return sum ;
       for( int i=0 ; i< m-1 ;i++ ){
        sum += v[i]*v[i+1] ;
       }
    return sum ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna