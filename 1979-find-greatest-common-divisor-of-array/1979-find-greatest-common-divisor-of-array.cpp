//more optimal solution tc = O(n) sc= O(1);

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mm = *max_element(nums.begin(), nums.end());

        return gcd(mn,mm);
    }
};

// tc= o(n log n) sc= o(1)
// class Solution {
// public:
//     int findGCD(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int n = nums.size();

//         for(int i = nums[0]; i>1; i--){
//             if(nums[0]%i == 0 && nums[n-1]%i == 0){
//                 return i;
//             }
//         }
//         return 1;
//     }
// };