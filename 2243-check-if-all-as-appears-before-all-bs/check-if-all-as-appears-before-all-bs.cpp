class Solution {
public:
    bool checkString(string s) {
        bool B = false;
        if(s.length() <= 1){
            return true;
        }
        for(int i = 0;i < s.length();i++){
           if(s[i] == 'a' && B){
            return false;
           }
           if(s[i] == 'b'){
             B = true;
           }
        }
        return true;
    }
};