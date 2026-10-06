class Solution {
public:
    int solve(vector<int>& cost){
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2;i < n;i++){
            int curr = min(prev1,prev2) + cost[i];

            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost);
    }
};