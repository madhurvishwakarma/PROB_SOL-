class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m - 1;
        // First find the correct row
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else if (matrix[mid][n - 1] < target) {
                left = mid + 1;
            } else {
                // Found the correct row, now search the column
                int row = mid;
                int l = 0, r = n - 1;
                while (l <= r) {
                    int m2 = l + (r - l) / 2;
                    if (matrix[row][m2] == target) return true;
                    else if (matrix[row][m2] < target) l = m2 + 1;
                    else r = m2 - 1;
                }
                return false;
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna