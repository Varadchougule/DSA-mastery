class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for(int k = 0; k < arr1.size(); k++) {
            int i = 0, j = arr2.size() - 1;
            bool flag = true;
            while(i <= j) {
                int mid = i + (j - i) / 2;
                if(abs(arr1[k] - arr2[mid]) <= d) {
                    flag = false;
                    break;
                }
                else if(arr2[mid] < arr1[k]) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
            if(flag) {
                count++;
            }
        }

        return count;
    }
};