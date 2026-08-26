class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1') ones++;

                if (ones == k) {
                    string cur = s.substr(i, j - i + 1);

                    if (cur.size() < minLen ||
                        (cur.size() == minLen && cur < ans)) {
                        minLen = cur.size();
                        ans = cur;
                    }

                    // Adding more characters can only increase the number
                    // of length, so stop for this starting position.
                    break;
                }
            }
        }

        return ans;
    }
};