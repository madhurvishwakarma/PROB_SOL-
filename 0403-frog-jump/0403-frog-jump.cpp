class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size() ;
        unordered_map<int,unordered_set<int>> dp ;
        for( auto x : stones ) dp[x] = {} ;
        dp[stones[0]].insert(0) ;
        for( int i=0 ; i<n ;i++ ){
            int pos = stones[i] ;
            for( auto k : dp[pos]){
                for( int steps : {k-1,k,k+1}){
                    if( steps <= 0) continue ;
                    int next = pos + steps ;
                    if( dp.count(next)){
                        dp[next].insert(steps) ;
                    }
                }
            }
        }
        return !dp[stones[n-1]].empty() ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna