class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> ones1, ones2;

        // Store coordinates of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        int ans = 0;

        // Try aligning every 1 in img1 with every 1 in img2
        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {

                int dr = r2 - r1;
                int dc = c2 - c1;

                int overlap = 0;

                for (auto [r, c] : ones1) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        img2[nr][nc] == 1) {
                        overlap++;
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};