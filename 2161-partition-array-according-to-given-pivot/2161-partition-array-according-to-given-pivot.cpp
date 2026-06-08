class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, equal, greater;

        for (int x : nums) {
            if (x < pivot)
                smaller.push_back(x);
            else if (x == pivot)
                equal.push_back(x);
            else
                greater.push_back(x);
        }

        vector<int> ans;

        ans.insert(ans.end(), smaller.begin(), smaller.end());
        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), greater.begin(), greater.end());

        return ans;
    }
};