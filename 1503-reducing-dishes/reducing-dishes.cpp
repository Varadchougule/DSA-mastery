class Solution {
public:
    int solve(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int index = n - 1;index >= 0;index--){
            for(int time = index;time >= 0;time--){
               int incl = satisfaction[index] * (time+1) + dp[index+1][time+1];
               int excl = 0 + dp[index+1][time];

               dp[index][time] = max(incl,excl);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        return solve(satisfaction);
    }
};