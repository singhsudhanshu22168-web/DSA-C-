class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        // If all numbers already have the same parity, we're done.
        bool hasOdd = false, hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // All even -> nums2 can simply be nums1
        if (!hasOdd)
            return true;

        // All odd -> nums2 can simply be nums1
        if (!hasEven)
            return true;

        // We have both odd and even numbers.
        // To make an odd number even, subtract an odd number.
        // To make an even number odd, subtract an odd number.
        //
        // Therefore, if there is at least one odd number,
        // every element can be made even by subtracting that odd number.
        //
        // But an odd element cannot subtract itself, so for n > 1
        // we need an odd number different from it.
        
        if (n == 1)
            return false;

        // Since nums1 contains both odd and even numbers,
        // every even element can use any odd element.
        // Every odd element can use an even element to remain odd.
        // Thus it is always possible.
        return true;
    }
};