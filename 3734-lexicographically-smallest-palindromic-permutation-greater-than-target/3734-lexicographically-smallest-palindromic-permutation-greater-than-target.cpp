class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if a palindromic permutation is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) return "";

        // Counts for the left half
        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        int m = n / 2;

        // Target's left half
        string prefix = target.substr(0, m);

        // Try to use target's left half exactly
        vector<int> remaining = halfCnt;
        bool exactPossible = true;

        for (char c : prefix) {
            int x = c - 'a';

            if (remaining[x] == 0) {
                exactPossible = false;
                break;
            }

            remaining[x]--;
        }

        // If target's left half is a valid permutation,
        // construct its palindrome and check if it is > target
        if (exactPossible) {
            string candidate = build(prefix, mid, n);

            if (candidate > target) {
                return candidate;
            }
        }

        /*
            Find the lexicographically smallest permutation
            of the left half that is strictly greater than prefix.

            We match target's prefix as long as possible.
            At every position, try replacing target[i] with
            the smallest available character greater than it.

            The rightmost valid replacement gives the smallest answer.
        */
        remaining = halfCnt;

        string best = "";

        for (int i = 0; i < m; i++) {
            int cur = prefix[i] - 'a';

            // Try increasing this position
            for (int c = cur + 1; c < 26; c++) {
                if (remaining[c] > 0) {
                    string left = prefix.substr(0, i);
                    left += char('a' + c);

                    vector<int> temp = remaining;
                    temp[c]--;

                    // Fill the remaining positions minimally
                    for (int k = 0; k < 26; k++) {
                        left.append(temp[k], char('a' + k));
                    }

                    best = left;
                    break;
                }
            }

            // Cannot continue matching target exactly
            if (remaining[cur] == 0) {
                break;
            }

            remaining[cur]--;
        }

        if (best.empty()) return "";

        return build(best, mid, n);
    }

private:
    string build(string left, char mid, int n) {
        string ans = left;

        if (n & 1) {
            ans += mid;
        }

        string right = left;
        reverse(right.begin(), right.end());

        ans += right;

        return ans;
    }
};