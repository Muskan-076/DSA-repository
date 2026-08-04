class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // ans type-1

        unordered_set<int> st(nums.begin(), nums.end());

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> ans;

        for(int i= mn+1; i< mx; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;

        // ans type-2


        // vector<int> ans;

        // int max_val = INT_MIN , min_val= INT_MAX;

        // for(int i =0 ; i< nums.size(); i++){

        //     // if(nums[i] > max){
        //     //     max = nums[i];
        //     // }
        //     // if(nums[i] < min){
        //     //     min = nums[i];
        //     // }

        //     max_val = max(max_val, nums[i]);
        //     min_val = min(min_val, nums[i]);

        // }

        // for(int j = min_val+1; j< max_val; j++){
        //     // if(j == nums.end()){
        //     //     ans.push_back(j);
        //     // }
        //     if(find(nums.begin(), nums.end(), j) == nums.end()){
        //         ans.push_back(j);
        //     }
        // }

        // return ans;


        // ans type-2


        // sort(nums.begin(), nums.end());
        // vector<int> ans;

        // for(int i =0; i< nums.size()-1; i++){
        //     int diff = nums[i+1] - nums[i];
        //     if(diff != 0 ){
        //         for(int j = nums[i]+1; j<nums[i]+diff ; j++){
        //             ans.push_back(j);
        //         }
                
        //     }
        // }
        // return ans;
    }
};