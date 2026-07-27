class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = 0;
        int maxi2 = 0;

        for (int num : nums) {
            if (num > maxi1) {
                maxi2 = maxi1;
                maxi1 = num;
            } 
            else if (num > maxi2) {
                maxi2 = num;
            }
        }

        return (maxi1 - 1) * (maxi2 - 1);
    }
};