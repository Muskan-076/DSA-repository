class Solution {
public:
    int countCommas(int n) {
        //tc =O(ologn)

        int ans = 0;

        int power = 1000;

        while( power <=n){
            ans += n - power +1;
            power *= 1000;
        }
        return ans;
        // if(n<1000) return 0;

        // int cnt =0;
        // for(int i =1000; i<= n; i++){
        //     int digit =0;
        //     int temp = i;

        //     while(temp > 0){
        //         digit++;
        //         temp /= 10;
        //     }

        //     cnt += (digit - 1) / 3;

        // }
        // return cnt;
    }
};