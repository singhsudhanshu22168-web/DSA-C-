import java.util.*;

class Solution {

    static class State {
        long score;
        int[] ids;

        State(long score, int[] ids) {
            this.score = score;
            this.ids = ids;
        }
    }

    public int[] maximumWeight(List<List<Integer>> intervals) {

        int n = intervals.size();

        // [left, right, weight, originalIndex]
        int[][] a = new int[n][4];

        for (int i = 0; i < n; i++) {
            a[i][0] = intervals.get(i).get(0);
            a[i][1] = intervals.get(i).get(1);
            a[i][2] = intervals.get(i).get(2);
            a[i][3] = i;
        }

        // Sort by right endpoint
        Arrays.sort(a, (x, y) -> {
            if (x[1] != y[1]) {
                return Integer.compare(x[1], y[1]);
            }
            return Integer.compare(x[3], y[3]);
        });

        // Right endpoints of sorted intervals
        int[] ends = new int[n];

        for (int i = 0; i < n; i++) {
            ends[i] = a[i][1];
        }

        /*
         * prev[i] = number of intervals before i
         * whose right endpoint is strictly less than
         * the left endpoint of interval i.
         */
        int[] prev = new int[n];

        for (int i = 0; i < n; i++) {
            prev[i] = lowerBound(ends, a[i][0]);
        }

        /*
         * dp[i][k]:
         * Best result using first i intervals
         * and choosing at most k intervals.
         */
        State[][] dp = new State[n + 1][5];

        // Empty selection
        for (int i = 0; i <= n; i++) {
            dp[i][0] = new State(0L, new int[0]);
        }

        for (int k = 1; k <= 4; k++) {
            dp[0][k] = new State(0L, new int[0]);
        }

        for (int i = 1; i <= n; i++) {

            int cur = i - 1;

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                State skip = dp[i - 1][k];

                // Option 2: take current interval
                State before = dp[prev[cur]][k - 1];

                int[] ids = addIndex(
                    before.ids,
                    a[cur][3]
                );

                State take = new State(
                    before.score + a[cur][2],
                    ids
                );

                dp[i][k] = better(take, skip)
                        ? take
                        : skip;
            }
        }

        return dp[n][4].ids;
    }

    /*
     * First position where arr[position] >= target.
     *
     * Therefore all positions before it satisfy:
     *
     * arr[position] < target
     */
    private int lowerBound(int[] arr, int target) {

        int left = 0;
        int right = arr.length;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    /*
     * Adds an index while keeping the array sorted.
     *
     * There can be at most 4 indices,
     * so this operation is effectively O(1).
     */
    private int[] addIndex(int[] arr, int x) {

        int[] result = new int[arr.length + 1];

        int i = 0;

        while (i < arr.length && arr[i] < x) {
            result[i] = arr[i];
            i++;
        }

        result[i] = x;

        while (i < arr.length) {
            result[i + 1] = arr[i];
            i++;
        }

        return result;
    }

    /*
     * Returns true if a is better than b.
     *
     * First maximize score.
     * If scores are equal, choose lexicographically
     * smaller index array.
     */
    private boolean better(State a, State b) {

        if (a.score != b.score) {
            return a.score > b.score;
        }

        return lexicographicallySmaller(a.ids, b.ids);
    }

    /*
     * Compare two sorted arrays lexicographically.
     */
    private boolean lexicographicallySmaller(int[] a, int[] b) {

        int len = Math.min(a.length, b.length);

        for (int i = 0; i < len; i++) {

            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }

        return a.length < b.length;
    }
}