class Solution {
public:

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        map<pair<int,int>,int>freq;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(img1[i][j] == 1){
                    int x1 = i;
                    int y1 = j;
                for(int k = 0;k < n;k++){
                    for(int l = 0;l < n;l++){
                       if(img2[k][l] == 1){
                        int x2 = k;
                        int y2 = l;
                       
                       int shiftX = x2 - x1;
                       int shiftY = y2 - y1;
   
                        freq[{shiftX,shiftY}]++;
                       }
                    }
                }
              }
            }
        }
         int maxi = 0;
            for(auto it : freq){
                maxi = max(it.second,maxi);
            }
            return maxi;
    }
};