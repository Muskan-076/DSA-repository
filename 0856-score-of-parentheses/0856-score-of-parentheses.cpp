class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {

            if (c == '(') {
                // Start a new nested level
                st.push(0);
            }
            else {
                // Score of the current level
                int curr = st.top();
                st.pop();

                // () -> 1
                // (A) -> 2 * A
                int score = (curr == 0) ? 1 : 2 * curr;

                // Add this score to the parent level
                st.top() += score;
            }
        }

        return st.top();
    }
};