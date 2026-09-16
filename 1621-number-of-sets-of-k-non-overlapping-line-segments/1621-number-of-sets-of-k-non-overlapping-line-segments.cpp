class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        // prev[i] = number of ways to make (j-1) segments
        // using the first i points.
        vector<long long> prev(n + 1, 1);
        vector<long long> cur(n + 1, 0);

        // Base case:
        // 0 segments can always be chosen in exactly 1 way.
        // prev[i] = 1 for all i.

        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), 0);

            long long prefix = 0;

            for (int i = 2; i <= n; i++) {
                // Add dp[i-1][j-1] to the prefix.
                // This represents all possible starting positions
                // of the new segment ending at point i-1.
                prefix = (prefix + prev[i - 1]) % MOD;

                // Option 1: don't use point i-1 as the end
                // Option 2: end a segment at i-1
                cur[i] = (cur[i - 1] + prefix) % MOD;
            }

            prev.swap(cur);
        }

        return prev[n];
    }
};