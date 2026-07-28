class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int MaxP = 0, best_buy = prices[0];
        for(int i = 1; i < n; i++){
            MaxP = max(MaxP, prices[i] - best_buy);
            best_buy = min(best_buy, prices[i]);
        }
        return MaxP;
    }
};