class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {};

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int first = 1; first <= 9; first++) {

            if (freq[first] == 0)
                continue;

            freq[first]--;

            for (int middle = 0; middle <= 9; middle++) {

                if (freq[middle] == 0)
                    continue;

                freq[middle]--;

                for (int last = 0; last <= 8; last += 2) {

                    if (freq[last] > 0) {
                        ans++;
                    }
                }

                freq[middle]++;
            }

            freq[first]++;
        }

        return ans;
    }
};