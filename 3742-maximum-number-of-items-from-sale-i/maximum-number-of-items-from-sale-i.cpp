class Solution {
public:
    int solve(int n,int budget,vector<vector<int>>& items,vector<int>&copies,int cheapestPrice){
        if(n < 0){
            return budget/cheapestPrice;
        }

        int take = 0;
        int nottake = 0;
        int price = items[n][1];

        if(price <= budget){
             take = copies[n] + solve(n-1,budget-price,items,copies,cheapestPrice);
        }
        nottake = solve(n-1,budget,items,copies,cheapestPrice);

        return max(take,nottake);
    }

    int solveMem(int n,int budget,vector<vector<int>>& items,vector<int>&copies,int cheapestPrice,vector<vector<int>>&dp){
        if(n < 0){
            return budget/cheapestPrice;
        }
        if(dp[n][budget] != -1){
            return dp[n][budget];
        }

        int take = 0;
        int nottake = 0;
        int price = items[n][1];


        if(price <= budget){
             take = copies[n] + solveMem(n-1,budget-price,items,copies,cheapestPrice,dp);
        }
        nottake = solveMem(n-1,budget,items,copies,cheapestPrice,dp);

        return dp[n][budget] = max(take,nottake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>copies(n,0);
        int cheapestPrice = INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(budget+1,-1));
        for(int i = 0;i < n;i++){
            cheapestPrice = min(cheapestPrice,items[i][1]);
        }
        for(int i = 0;i < n;i++){
            int copy = 0;
            for(int j = 0;j < n;j++){
                if(j == i){
                    continue;
                }
                if(items[j][0] % items[i][0] == 0){
                    copy++;
                }
            }
            copies[i] = copy+1;
        }
        return solveMem(n-1,budget,items,copies,cheapestPrice,dp);
    }
};