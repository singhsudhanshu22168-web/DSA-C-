class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // A comma exists after every group of 3 digits.
        // 1000 -> comma after the first digit
        // 1000000 -> two possible comma positions, etc.
        for (long long p = 1000; p <= n; ) {
            ans += n - p + 1;

            // Move to the next comma position:
            // 1000 -> 1000000 -> 1000000000 -> ...
            if (p > n / 1000) break;
            p *= 1000;
        }

        return ans;
    }
};