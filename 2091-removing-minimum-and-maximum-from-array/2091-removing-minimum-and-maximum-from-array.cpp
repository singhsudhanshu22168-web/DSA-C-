class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find positions of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // 1. Delete both from the front
        int fromFront = right + 1;

        // 2. Delete both from the back
        int fromBack = n - left;

        // 3. Delete one from front and one from back
        int bothSides = (left + 1) + (n - right);

        return min({fromFront, fromBack, bothSides});
    }
};