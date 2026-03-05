class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count1 = 0; // starting with '0'
        int count2 = 0; // starting with '1'
        
        for(int i = 0; i < n; i++) {
            // Pattern 1: "010101..."
            if(i % 2 == 0) {
                if(s[i] != '0') count1++;
                if(s[i] != '1') count2++;
            } 
            else {
                if(s[i] != '1') count1++;
                if(s[i] != '0') count2++;
            }
        }
        
        return min(count1, count2);
    }
};