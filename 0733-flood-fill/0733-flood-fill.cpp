class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() ;
        int m = image[0].size() ;
        vector<vector<int>> vis( n , vector<int>( m , 0 )) ;
        queue<pair<int, int>> q ;
        q.push({sr,sc}) ;
        vis[sr][sc] = 1 ;
        int start  = image[sr][sc] ;
        image[sr][sc] = color ;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && image[nr][nc] == start) {
                    image[nr][nc] = color;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return image ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna