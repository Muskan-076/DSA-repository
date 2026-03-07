class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s + s;
        
        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        int left = 0;
        
        for(int right = 0; right < s.size(); right++) {
            
            char expected1 = (right % 2) ? '1' : '0';
            char expected2 = (right % 2) ? '0' : '1';
            
            if(s[right] != expected1) diff1++;
            if(s[right] != expected2) diff2++;
            
            if(right - left + 1 > n) {
                char leftExpected1 = (left % 2) ? '1' : '0';
                char leftExpected2 = (left % 2) ? '0' : '1';
                
                if(s[left] != leftExpected1) diff1--;
                if(s[left] != leftExpected2) diff2--;
                
                left++;
            }
            
            if(right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }
        
        return ans;
    }
};