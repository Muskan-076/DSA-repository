class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // optimal soln tc =O(n^2) sc= o(1)
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i =0; i< n-2; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while(left < right){

            int sum = nums[i] + nums[left] + nums[right];

            if(sum<0) {
                left++;
            }
            else if(sum > 0){
                right--;
            }
            else{
                ans.push_back({nums[i], nums[left], nums[ right]});

                while(left< right && nums[left] == nums[left+ 1]){
                    left++;
                }
                while(left< right && nums[right] == nums[right - 1]){
                    right--;
                }

                left++;
                right--;

            }
            }

        }
        return ans;

        // // tc = o(n^3log m) sc= o(m)
        // int n = nums.size();

        // set<vector<int>> st;

        // for(int i =0; i< n; i++){
        //     for(int j = i+1; j<n; j++){
        //         for(int k= j+1; k<n; k++){

        //             if(nums[i] + nums[j] + nums[k] == 0){

        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());

        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());

        // return ans;
    }
};