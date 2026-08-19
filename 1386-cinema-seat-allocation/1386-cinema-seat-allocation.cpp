class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask for each affected row.
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            rows[row] |= (1 << s);
        }

        long long ans = 2LL * (n - rows.size());

        // Masks for:
        // [2,3,4,5]
        // [4,5,6,7]
        // [6,7,8,9]
        int left  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : rows) {
            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                // Two non-overlapping groups.
                ans += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                // At least one group can be placed.
                ans += 1;
            }
        }

        return (int)ans;
    }
};