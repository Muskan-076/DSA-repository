class Solution {
public:
    int minOperations(string s, int k) {
        int z = 0;
        for(char c : s)
            if(c == '0') z++;
        
        if(z == 0) return 0;
        if(k == 1) return z;
        
        long long t = (z + k - 1) / k;  // ceil(z/k)
        
        if((t * k - z) % 2 == 0)
            return t;
        
        if(k % 2 == 0)
            return -1;
        
        return t + 1;
    }
};