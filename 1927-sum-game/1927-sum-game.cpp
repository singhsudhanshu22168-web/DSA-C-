class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int sumLeft = 0, sumRight = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                sumLeft += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                sumRight += num[i] - '0';
        }

        // If number of '?' is odd, Alice always wins
        if ((qLeft + qRight) % 2 != 0)
            return true;

        // Difference in known sums
        int diff = sumLeft - sumRight;

        // Alice can win unless the unknown digits can be perfectly balanced
        return diff != (qRight - qLeft) * 9 / 2;
    }
};