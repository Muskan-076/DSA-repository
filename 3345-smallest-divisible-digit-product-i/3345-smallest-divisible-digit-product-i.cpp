class Solution {
public:
    int digitProduct(int x){
        int prod = 1;

        if(x==0) return 0;

        while(x>0){
            prod *= (x % 10);
            x /= 10;
        }

        return prod;
    }
    int smallestNumber(int n, int t) {
        int num = n;

        while(true){
            if(digitProduct(num) % t == 0){
                return num;
            }
            num++;
        }
    }
};