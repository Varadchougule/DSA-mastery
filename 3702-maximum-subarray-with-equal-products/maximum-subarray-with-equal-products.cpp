class Solution {
public:
    long long GCD(vector<int>&nums,int i,int j){
        long long g = nums[i];
        for(int k = i+1;k <= j;k++){
            g = gcd(g,nums[k]);
        }
        return g;
    }
    long long LCM(vector<int>&nums,int i,int j){
        long long l = nums[i];
        for(int k = i+1;k <= j;k++){
            l = lcm(l,nums[k]);
        }
        return l;
    }
    long long product(vector<int>&nums,int i,int j){
        long long prod = nums[i];
        for(int k = i+1;k <= j;k++){
          if(prod > LLONG_MAX / nums[k]) {
                return LLONG_MAX;
            }

            prod *= nums[k];
        }
        return prod;
    }
    int maxLength(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = i;j < nums.size();j++){
                long long gcd = GCD(nums,i,j);
                long long lcm = LCM(nums,i,j);
                long long prod = product(nums,i,j);
                if(prod == lcm * gcd){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};