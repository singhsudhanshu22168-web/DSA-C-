class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // first[c] = first occurrence of c
        // last[c]  = last occurrence of c
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Build the smallest valid interval starting at first[c]
        for (int c = 0; c < 26; c++) {
            if (first[c] == n)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                // This character occurs before l,
                // so we cannot make a valid substring starting at l.
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // We must include ALL occurrences of this character.
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position.
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second != b.second)
                     return a.second < b.second;

                 // For the same end, prefer shorter interval.
                 return a.first > b.first;
             });

        vector<string> ans;

        int prevEnd = -1;

        for (auto &[l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};