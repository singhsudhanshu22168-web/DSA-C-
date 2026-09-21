class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        // dp[r] = number of subarrays ending at the previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        // ans[r] = number of all subarrays whose product % k == r
        vector<long long> ans(k, 0);

        for (int x : nums) {
            int a = x % k;

            vector<long long> ndp(k, 0);

            // Start a new subarray with only nums[i]
            ndp[a]++;

            // Extend every subarray ending at previous position
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRem = (r * a) % k;
                ndp[newRem] += dp[r];
            }

            // Add all subarrays ending at current position
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};