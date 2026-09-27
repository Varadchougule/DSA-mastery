class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string curr = "";
       for(char ch : s) {
            if(ch == '(') {
                st.push(curr);
                curr = "";
            }
            else if(ch == ')') {
                string previous = st.top();
                st.pop();

                reverse(curr.begin(), curr.end());

                curr = previous + curr;
            }
            else {
                curr.push_back(ch);
            }
        }

        return curr;
    }
};