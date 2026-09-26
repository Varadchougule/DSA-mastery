class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &k : knowledge){
            mp[k[0]] = k[1];
        }
        string ans = "";
        for(int i = 0;i < s.length();i++){
            if(s[i] == '('){
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp.push_back(s[i]);
                    i++;
                }
               ans += mp.count(temp) ? mp[temp] : "?";
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};