class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sumDiff = 0;
        int qDiff = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                qDiff++;
            } else {
                sumDiff += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                qDiff--;
            } else {
                sumDiff -= num[i] - '0';
            }
        }

        // Equal number of '?' on both sides
        if (qDiff == 0) {
            return sumDiff != 0;
        }

        // Bob wins only if this exact equality is possible
        return 2 * sumDiff != -9 * qDiff;
    }
};