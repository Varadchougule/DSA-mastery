class Solution {
public:
    int reverseDegree(string s) {
        long long sum = 0;

    for (int i = 0; i < s.length(); i++) {
        int ch = 'z' - s[i] + 1;
            sum += 1LL * ch * (i+1);
    }
        return sum;
    }
};