class Solution {
public:
    int minInsertions(string s) {
        stack<int>st;
        int ans = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '('){
                st.push('(');
            }else{
              if(i + 1 < s.length() && s[i + 1] == ')'){
                i++;
              }else{
                ans++;
              }

              if(!st.empty()){
                st.pop();
              }else{
                ans++;
              }
            }
        }
        ans += 2 * st.size();
        return ans;
    }
};