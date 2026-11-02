class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int mid = nums.size() / 2;
        int n = nums[mid];
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            if( i == mid){
                continue;
            }
            ans += abs(n - nums[i]);
        }
        return ans;
    }
};