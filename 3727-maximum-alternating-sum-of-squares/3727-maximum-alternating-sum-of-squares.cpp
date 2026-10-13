
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        
        for (int x : nums) {
            sq.push_back(1LL * x * x);
        }
        
        sort(sq.begin(), sq.end());
        
        long long ans = 0;
        int n = sq.size();
        
        for (int i = 0; i < n / 2; i++) {
            ans -= sq[i];
        }
        
        for (int i = n / 2; i < n; i++) {
            ans += sq[i];
        }
        
        return ans;
    }
};
