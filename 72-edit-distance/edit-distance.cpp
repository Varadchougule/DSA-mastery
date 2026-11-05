class Solution {
public:
    int solve(string &word1, string &word2,int i,int j){
        if(i == word1.length()){
            return word2.length() - j;
        }
        if(j == word2.length()){
            return word1.length() - i;
        }
        
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = solve(word1,word2,i+1,j+1);
        }else{
            int insertAns = 1 + solve(word1,word2,i,j+1);
            int deleteAns = 1 + solve(word1,word2,i+1,j);
            int replaceAns = 1 + solve(word1,word2,i+1,j+1);

            ans = min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;
    }

    int solveMem(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
        if(i == word1.length()){
            return word2.length() - j;
        }
        if(j == word2.length()){
            return word1.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = solveMem(word1,word2,i+1,j+1,dp);
        }else{
            int insertAns = 1 + solveMem(word1,word2,i,j+1,dp);
            int deleteAns = 1 + solveMem(word1,word2,i+1,j,dp);
            int replaceAns = 1 + solveMem(word1,word2,i+1,j+1,dp);

            ans = min(insertAns,min(deleteAns,replaceAns));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveMem(word1,word2,0,0,dp);
    }
};