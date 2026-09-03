
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0)
                minEven = min(minEven, x);
            else
                minOdd = min(minOdd, x);
        }

        // All numbers are already even
        if (minOdd == INT_MAX)
            return true;

        // If there are no even numbers, all are already odd
        if (minEven == INT_MAX)
            return true;

        // Every even number must have a smaller odd number
        return minOdd < minEven;
    }
};