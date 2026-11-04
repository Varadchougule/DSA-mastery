class Solution {
public:
    int solveSO(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 1; buy >= 0; buy--) {
            for(int limit = 1; limit <= 2; limit++) {

                if(buy) {
                    int buyKaro = -prices[index] + next[0][limit];
                    int skipKaro = next[1][limit];

                    curr[buy][limit] = max(buyKaro, skipKaro);
                }
                else {
                    int sellKaro = prices[index] + next[1][limit-1];
                    int skipKaro = next[0][limit];

                    curr[buy][limit] = max(sellKaro, skipKaro);
                }
            }
        }

        next = curr;
    }

    return next[1][2];
}
    int maxProfit(vector<int>& prices) {
        return solveSO(prices);
    }
};