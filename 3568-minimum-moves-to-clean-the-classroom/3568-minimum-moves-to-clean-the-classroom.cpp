class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign an ID to every L.
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } 
                else if (classroom[r][c] == 'L') {
                    id[r][c] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // best[r][c][mask] =
        // maximum remaining energy with which we reached this state.
        //
        // If we reach (r,c,mask) again with <= best energy,
        // that state is dominated and can be ignored.
        int states = 1 << litterCount;

        vector<int> best(m * n * states, -1);

        auto index = [&](int r, int c, int mask) {
            return ((r * n + c) * states + mask);
        };

        struct State {
            int r, c;
            int mask;
            int energy;
        };

        queue<State> q;

        best[index(sr, sc, 0)] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                // Cannot move without energy.
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int idx = index(nr, nc, nmask);

                    // Dominated state:
                    // We have already reached this state with
                    // equal or more energy.
                    if (best[idx] >= ne)
                        continue;

                    best[idx] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }

            ++moves;
        }

        return -1;
    }
};