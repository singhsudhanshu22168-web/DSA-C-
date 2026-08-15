class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) {
                hasNonZero = true;
            }
        }

        // Entire array has non-zero XOR
        if (totalXor != 0) {
            return n;
        }

        // XOR of entire array is 0, but we can remove one non-zero element
        if (hasNonZero) {
            return n - 1;
        }

        // All elements are 0
        return 0;
    }
};