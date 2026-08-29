class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        vector<int> ans = nums;

        int start = 0;

        while (start < n) {
            int end = start;

            // Find the complete connected group
            while (end + 1 < n &&
                   (long long)v[end + 1].first - v[end].first <= limit) {
                end++;
            }

            // Get all indices in this group
            vector<int> indices;
            vector<int> values;

            for (int i = start; i <= end; i++) {
                values.push_back(v[i].first);
                indices.push_back(v[i].second);
            }

            // Smallest values should go to smallest indices
            sort(indices.begin(), indices.end());

            for (int i = 0; i < (int)indices.size(); i++) {
                ans[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return ans;
    }
};