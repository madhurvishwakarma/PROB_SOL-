class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ;
        int Min = INT_MAX ;
        for( int i =0 ; i<prices.size() ; i++ ){
            Min = min( Min , prices[i]) ;
            profit = max( profit , prices[i] -Min) ;
        }
        return profit ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna