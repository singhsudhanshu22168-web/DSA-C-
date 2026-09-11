class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        // Count occurrences of each digit
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Hundreds digit: 1-9 (no leading zero)
        for (int h = 1; h <= 9; h++) {
            if (freq[h] == 0) continue;
            freq[h]--;

            // Tens digit: 0-9
            for (int t = 0; t <= 9; t++) {
                if (freq[t] == 0) continue;
                freq[t]--;

                // Units digit must be even
                for (int u = 0; u <= 8; u += 2) {
                    if (freq[u] > 0) {
                        ans++;
                    }
                }

                freq[t]++;
            }

            freq[h]++;
        }

        return ans;
    }
};