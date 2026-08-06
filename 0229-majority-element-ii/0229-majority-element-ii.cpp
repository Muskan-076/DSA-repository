class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //tc =o(n) , sc= o(1)

        unordered_map<int,int> freq;
        vector<int> ans;

        

        for(int x : nums){
            freq[x]++;
        }
        
        for(auto it : freq){
            if(it.second > nums.size()/3){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};