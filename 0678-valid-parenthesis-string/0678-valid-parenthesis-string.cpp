class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }

            else if (ch == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;      // treat '*' as ')'
                high++;     // treat '*' as '('
            }

            // We cannot have fewer than 0 unmatched '('
            if (low < 0) {
                low = 0;
            }

            // Even the maximum possibility has too many ')'
            if (high < 0) {
                return false;
            }
        }

        // If minimum possible unmatched '(' is 0,
        // we can make the string valid.
        return low == 0;
    }
};