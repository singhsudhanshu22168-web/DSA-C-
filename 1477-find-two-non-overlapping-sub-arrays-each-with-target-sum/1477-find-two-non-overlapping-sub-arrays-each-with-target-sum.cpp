class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0 ... i-1]
        vector<int> best(n + 1, INF);

        int ans = INF;
        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Since all elements are positive, shrink from left
            // while the sum is >= target.
            while (sum > target) {
                sum -= arr[left++];
            }

            // If we found a subarray [left...right] with sum = target
            if (sum == target) {
                int len = right - left + 1;

                // best[left] contains the shortest valid subarray
                // completely before this one.
                if (best[left] != INF) {
                    ans = min(ans, len + best[left]);
                }

                // Store the shortest valid subarray ending at or before right
                best[right + 1] = min(best[right], len);
            } else {
                best[right + 1] = best[right];
            }
        }

        return ans == INF ? -1 : ans;
    }
};