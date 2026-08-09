class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //optimal soln
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n= nums.size();

        for(int i= 0; i<n-3; i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j<n-2; j++){
                if(j> i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = n-1;

                while(left<right){

                    long long sum = (long long)nums[i]+ nums[j] + nums[left] + nums[right];

                    if(sum < target){
                        left++;
                    }
                    else if(sum> target) right--;
                    else{
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        while(left < right && nums[left] == nums[left+1]) 
                            left++;

                        while(left<right && nums[right] == nums[right -1]) right--;

                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;

        // brute-force soln tc= o(n^4 logn) sc= o(n^4)

        // int n = nums.size();
        // set<vector<int>> st;
        
        // for(int i = 0 ; i< n; i++){
        //     for(int j = i+1; j< n; j++){
        //         for(int k = j+1; k< n; k++){
        //             for(int a= k+1; a<n; a++){
        //                 if(nums[i] + nums[j]+ nums[k] + nums[a] == target){
        //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[a]};
        //                     sort(temp.begin(), temp.end());
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;
    }
};