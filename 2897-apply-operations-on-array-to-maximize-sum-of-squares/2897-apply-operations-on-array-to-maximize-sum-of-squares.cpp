class Solution {
public:
    int maxSum(vector<int>& nums, int k ) {
       int MOD = 1e9 + 7 ;
       vector<int> count( 32 , 0 ) ;
       for( auto x : nums ){
        for( int b=0 ; b<32 ; b++ ){
            if( x&(1<<b)) count[b]++ ;
        }
       }
       long long ans = 0 ;
       while(k--){
         long long curr =0 ;
         for( int b=0 ; b<32 ; b++ ){
            if( count[b] > 0){
                count[b]-- ;
                curr = curr|(1<<b) ;
            }
         }
         ans = (ans + (curr*curr))%MOD ;
       }
       return ans ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna