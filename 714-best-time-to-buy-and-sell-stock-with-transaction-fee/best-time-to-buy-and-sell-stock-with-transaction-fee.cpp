class Solution {
public:
// problem no 122 and this is same just we have add transaction fee in this so so add trancsaction fees when we sell a stock means one traction  is completed  
    int solveSO(vector<int>&prices,int fees){
        int n = prices.size();
        vector<int>next(3,0);
        vector<int>curr(3,0);

        for(int index = n-1;index >= 0;index--){
            for(int buy = 1;buy >= 0;buy--){

            if(buy){
                int buyKaro = -prices[index] + next[0];
                int skipKaro = 0 + next[1];
                curr[buy] = max(buyKaro,skipKaro);
            }else{
                int sellKaro = prices[index] - fees + next[1];
                int skipKaro = 0 + next[0];
               curr[buy] = max(sellKaro,skipKaro);
            }
            }
            next = curr;
        }
       return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveSO(prices,fee);
    }
};