class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> map;
        for(int i = 0;i < nums.size();i++){
            map[nums[i]].push_back(i);
        }

        for(int i = 0;i < nums.size();i++){
            int required = target - nums[i];
            
            auto it = map.find(required);
            if(it != map.end()){
               for (int index : it->second) {
                    if (index != i) {
                        return {i, index};
                    }
                }
            }
        }
        return {-1,-1};
    }
};