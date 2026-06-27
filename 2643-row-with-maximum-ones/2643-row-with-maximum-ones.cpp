class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;
        int index = 0 , curr = 0 ;
        for( int i =0 ; i< n ; i++ ){
            int count = 0 ;
            for( int j = 0 ; j < m ; j++ ){
                if( mat[i][j] == 1){
                    count++ ;
                }
            }
            if( curr < count ){
                curr = count ;
                index = i ;
            }
        }
        return {index , curr } ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna