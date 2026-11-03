class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == maxi){
                continue;
            }
            moves += (maxi - nums[i]);
        }
        return moves;
    }
};