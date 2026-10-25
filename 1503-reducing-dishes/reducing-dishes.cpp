class Solution {
public:
    int solve(vector<int>& satisfaction){
        int n = satisfaction.size();

        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        for(int index = n - 1;index >= 0;index--){
            for(int time = index;time >= 0;time--){
               int incl = satisfaction[index] * (time+1) + next[time+1];
               int excl = 0 + next[time];

               curr[time] = max(incl,excl);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        return solve(satisfaction);
    }
};