class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            int n = nums[i];
            int digit = 0;
            int sum = 0;
            while(n > 0){
               digit = n % 10;
               n = n / 10;
               sum += digit;
            }
            if(i == sum){
                return i;
            }
        }
        return -1;
    }
};