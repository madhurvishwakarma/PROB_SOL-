class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1, litterCount = 0;
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') litterId[i][j] = litterCount++;
            }
        }
        if (litterCount == 0) return 0;

        int fullMask = (1 << litterCount) - 1;
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(
                energy + 1, vector<bool>(1 << litterCount, false))));

        queue<tuple<int,int,int,int>> q;   // row, col, energyLeft, mask
        q.push({sr, sc, energy, fullMask});
        vis[sr][sc][energy][fullMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [row, col, eng, mask] = q.front();
                q.pop();

                if (mask == 0) return moves;
                if (eng == 0) continue;   // stuck here, can't extend further

                for (int d = 0; d < 4; d++) {
                    int nr = row + dr[d], nc = col + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int nEng = (classroom[nr][nc] == 'R') ? energy : eng - 1;
                    int nMask = mask;
                    if (classroom[nr][nc] == 'L' && (mask & (1 << litterId[nr][nc])))
                        nMask &= ~(1 << litterId[nr][nc]);

                    if (!vis[nr][nc][nEng][nMask]) {
                        vis[nr][nc][nEng][nMask] = true;
                        q.push({nr, nc, nEng, nMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna