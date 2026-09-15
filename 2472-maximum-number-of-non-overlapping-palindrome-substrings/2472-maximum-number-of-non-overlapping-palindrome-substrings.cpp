class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[l][r] = true if s[l...r] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len - 1;

                if (len == 1) {
                    pal[l][r] = true;
                }
                else if (len == 2) {
                    pal[l][r] = (s[l] == s[r]);
                }
                else {
                    pal[l][r] = (s[l] == s[r] && pal[l + 1][r - 1]);
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; ++r) {
            // Don't use a palindrome ending at r
            dp[r + 1] = dp[r];

            // Try every palindrome ending at r
            for (int l = 0; l <= r; ++l) {
                if (r - l + 1 >= k && pal[l][r]) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};