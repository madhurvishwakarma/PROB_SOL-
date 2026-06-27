class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size() ;
        int m = matrix.size() ;
        int left = 0 , right = m-1 , up = 0 , down = n-1 ;
        while( left <= right ){
            int mid = left + (right - left)/2 ;
            up = 0 ;
            while( up <= down ){if( matrix[mid][up] == target ){
                return true ;
            }
            else if( matrix[mid][up] < target ){
                left = mid+1 ;
            }
            else {
                right = mid-1 ;
            }
            up++ ;
            }
        }
        return false ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna