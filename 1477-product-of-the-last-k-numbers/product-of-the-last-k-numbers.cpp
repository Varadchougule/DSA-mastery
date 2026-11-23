class ProductOfNumbers {
public:
    vector<int>nums = {};
    ProductOfNumbers() {
        nums = {};
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int sum = 1;
        int i = nums.size()-1;
        while(k != 0){
            sum *= nums[i];
            i--;
            k--;
        }
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */