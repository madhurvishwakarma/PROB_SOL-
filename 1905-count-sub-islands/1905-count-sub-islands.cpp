class Solution {
public:
    int bfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis) {
        int n = grid2.size(), m = grid2[0].size();
        vis[r][c] = 1;
        queue<pair<int,int>> q;
        q.push({r, c});
        int badCells = 0;
        if (grid1[r][c] == 0) badCells++;  

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] == 0 && grid2[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    if (grid1[nr][nc] == 0) badCells++;
                }
            }
        }
        return badCells;   // 0 means every cell of this grid2 island exists in grid1 too
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(), m = grid2[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && vis[i][j] == 0) {
                    if (bfs(i, j, grid1, grid2, vis) == 0) count++;
                }
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna