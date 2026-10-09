
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                // If an unmatched ')' is needed, insert it
                if (need % 2 == 1) {
                    insertions++;
                    need--;
                }

                // Every '(' needs two ')'
                need += 2;
            } 
            else {
                need--;

                // Too many closing parentheses
                if (need < 0) {
                    insertions++;
                    need = 1;
                }
            }
        }

        // Insert any missing closing parentheses
        return insertions + need;
    }
};
