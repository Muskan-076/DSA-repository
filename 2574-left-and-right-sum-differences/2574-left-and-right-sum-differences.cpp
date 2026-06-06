class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSum(n);
        vector<int> rightSum(n);

        leftSum[0] = 0;
        for(int i = 1; i < n; i++) {
            int lsum = 0;
            for(int j = 0; j < i; j++) {
                lsum += nums[j];
            }
            leftSum[i] = lsum;
        }

        rightSum[n-1] = 0;
        for(int i = 0; i < n; i++) {
            int rsum = 0;
            for(int j = i+1; j < n; j++) {
                rsum += nums[j];
            }
            rightSum[i] = rsum;
        }

        vector<int> answer(n);
        for(int i = 0; i < n; i++) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
};