class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // pair<int, int> small = {0, -1};
        // for(int i =0; i< prices.size(); i++){
        //     if(prices[i] < small.first){
        //         small = {prices[i], i};
        //     }
        // }
        // int a = small.second;
        // int lar = 0;
        // for(int j = a; j < prices.size(); j--){
        //     if(prices[j] > lar ){
        //         lar = prices[j];
        //     }
        // }
        // return lar - small.first;

        int mini = prices[0];
        int maxProfit = 0;

        int n = prices.size();

        for(int i =0; i<n; i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};