class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n)
            return 0;

        const long long LIMIT = INT_MAX + 1LL;

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = min(i + 1, m); j >= 1; j--) {

                if (s[i] == t[j - 1]) {

                    dp[j] = min(LIMIT, dp[j] + dp[j - 1]);

                }
            }
        }

        return (int)dp[m];
    }
};