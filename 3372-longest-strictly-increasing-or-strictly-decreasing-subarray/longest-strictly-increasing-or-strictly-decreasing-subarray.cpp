
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing = 1;
        int decreasing = 1;
        int ans = 1;
        int ansInc = 1;
        int ansDec = 1;

        for(int i = 1; i < nums.size(); i++){
            int j = i - 1;

            if(nums[i] > nums[j]){
                increasing++;
                decreasing = 1;
                ansInc = max(ansInc, increasing);
            }

            else if(nums[i] < nums[j]){
                decreasing++;
                increasing = 1;
                ansDec = max(ansDec, decreasing);
            }

            else{
                increasing = 1;
                decreasing = 1;
            }

            ans = max(ans, max(ansInc, ansDec));
        }

        return ans;
    }
};
