class Solution {
public:
    using ll = long long;

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: [left, right, weight, original_index]
        vector<array<ll, 4>> a(n);

        for (int i = 0; i < n; ++i) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by left endpoint, then by original index
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0]) return x[0] < y[0];
            return x[3] < y[3];
        });

        // next[i] = first interval whose left > a[i].right
        // Strictly greater because touching intervals overlap.
        vector<int> next(n);

        vector<ll> starts(n);
        for (int i = 0; i < n; ++i)
            starts[i] = a[i][0];

        for (int i = 0; i < n; ++i) {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        /*
            dp[i][k] = best answer using intervals from i onward,
                       choosing at most k intervals.

            Each state stores:
            - maximum total weight
            - lexicographically smallest list of original indices
        */

        struct State {
            ll score = 0;
            vector<int> indices;
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));

        // Compare two states:
        // 1. Higher score is better.
        // 2. If score is equal, lexicographically smaller indices are better.
        auto better = [](const State& x, const State& y) {
            if (x.score != y.score)
                return x.score > y.score;

            return lexicographical_compare(
                x.indices.begin(), x.indices.end(),
                y.indices.begin(), y.indices.end()
            );
        };

        for (int i = n - 1; i >= 0; --i) {

            // k = maximum number of intervals we may still choose
            for (int k = 1; k <= 4; ++k) {

                // Option 1: Skip current interval
                State skip = dp[i + 1][k];

                // Option 2: Take current interval
                State take;
                take.score = a[i][2] + dp[next[i]][k - 1].score;
                take.indices.push_back((int)a[i][3]);

                // The final answer must be sorted by index.
                for (int idx : dp[next[i]][k - 1].indices)
                    take.indices.push_back(idx);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].indices;
    }
};