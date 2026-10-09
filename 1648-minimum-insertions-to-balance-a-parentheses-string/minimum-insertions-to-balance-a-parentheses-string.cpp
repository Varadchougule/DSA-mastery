class Solution {
public:
    int minInsertions(string s) {
        int balence = 0;
        int ans = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '('){
                balence += 2;
            }else{
              if(i + 1 < s.length() && s[i + 1] == ')'){
                i++;
              }else{
                ans++;
              }

              if(balence > 0){
                balence -= 2;
              }else{
                ans++;
              }
            }
        }
        ans += balence;
        return ans;
    }
};