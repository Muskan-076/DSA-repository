class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<string> st;
        string curr = "";
        
        for (char c : s) {
            
            if (c == '(') {
                // Save the string before entering parentheses
                st.push(curr);
                curr = "";
            }
            
            else if (c == ')') {
                // Reverse the string inside parentheses
                reverse(curr.begin(), curr.end());
                
                // Add it to the string before '('
                curr = st.top() + curr;
                st.pop();
            }
            
            else {
                // Normal character
                curr += c;
            }
        }
        
        return curr;
    }
};