class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;

        for(int i =0; i< n; i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
            if(nums[i] < nums[minIdx]){
                minIdx =i ;
            }
        }

        int left = min(minIdx, maxIdx);
        int right = max(maxIdx, minIdx);

        int fromFront = right +1;

        int fromBack = n - left;

        int bothSides = (left+1) + (n- right);

        return min({fromFront, fromBack, bothSides});
    }
};