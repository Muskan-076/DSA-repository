class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);
        int posIndex = 0, negIndex = 1;

        for(int i =0 ; i< n ; i++){

            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
        // int n = nums.size();
        // vector<int> ans(n);


        // vector<int> pos;
        // vector<int> neg;

        // for(int i =0; i< n; i++){
        //     if(nums[i] > 0){
        //         pos.push_back(nums[i]);
        //     }
        //     else{
        //         neg.push_back(nums[i]);
        //     }
        // }

        // for(int i =0; i< n; i++){
        //     if(i % 2 == 0){
        //         ans[i] = pos[i/2];
        //     }
        //     else{
        //         ans[i] = neg[i/2];
        //     }
        // }
        // return ans;
    }
};