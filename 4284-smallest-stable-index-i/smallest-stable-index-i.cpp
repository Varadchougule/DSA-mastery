class Solution {
public:
    int MinMax(vector<int>nums,int x){
        int maxi = nums[0];
        int mini = nums[x];
        for(int i = 0;i <= x;i++){
            maxi = max(maxi,nums[i]);
        }
        for(int i = x;i < nums.size();i++){
            mini = min(mini,nums[i]);
        }

        int instability = maxi - mini;
        return instability;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i = 0;i<nums.size();i++){
            int ans = MinMax(nums,i);
            if(ans <= k){
                return i;
            }
        }
        return -1;
    }
};