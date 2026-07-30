class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int quotient = n/8;
        int remainder = n%8;

        int ans;

        if(quotient == 3){
            ans = 8 + 2*8 + 3*8 + 4*remainder;
        }

        else if(quotient == 2){
            ans = 8 + 2*8 +3*remainder;
        }
        else if(quotient == 1){
            ans = 8 + 2*remainder;
        }
        else {
            ans = 1*remainder;
        }

        return ans;
    }
};