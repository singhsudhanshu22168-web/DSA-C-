class Solution {
public:
    using int64 = long long;

    // Count positive integers <= x that are divisible by
    // at least one coin.
    long long countValid(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long lcm = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;

                    long long g = gcd(lcm, (long long)coins[i]);
                    lcm = lcm / g * coins[i];

                    if (lcm > x) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow)
                continue;

            long long multiples = x / lcm;

            // Inclusion-Exclusion
            if (bits & 1)
                count += multiples;
            else
                count -= multiples;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        long long low = 1;

        // The kth valid number cannot be greater than k * min(coins).
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long high = minCoin * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countValid(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};