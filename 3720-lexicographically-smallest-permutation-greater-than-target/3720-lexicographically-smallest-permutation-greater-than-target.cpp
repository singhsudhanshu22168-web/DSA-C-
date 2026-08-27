class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        string ans;

        // Match target from left to right as long as possible.
        int matched = 0;

        while (matched < n &&
               cnt[target[matched] - 'a'] > 0) {
            
            ans += target[matched];
            cnt[target[matched] - 'a']--;
            matched++;
        }

        /*
         * Try the rightmost possible position first.
         *
         * pos = matched:
         *   target[pos] was NOT matched, so ans currently contains
         *   target[0 ... pos-1].
         *
         * pos < matched:
         *   restore target[pos] before trying a larger character.
         */
        for (int pos = matched; pos >= 0; pos--) {

            // No valid position when matched == n and pos == n.
            if (pos == n) {
                continue;
            }

            // If this position was part of the matched prefix,
            // remove it and restore its character.
            if (pos < matched) {
                cnt[ans.back() - 'a']++;
                ans.pop_back();
            }

            int targetChar = target[pos] - 'a';

            // Choose the smallest available character
            // strictly greater than target[pos].
            int greaterChar = -1;

            for (int c = targetChar + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    greaterChar = c;
                    break;
                }
            }

            if (greaterChar != -1) {
                ans += char('a' + greaterChar);
                cnt[greaterChar]--;

                // Append the remaining characters in sorted order.
                for (int c = 0; c < 26; c++) {
                    ans.append(cnt[c], char('a' + c));
                }

                return ans;
            }
        }

        return "";
    }
};