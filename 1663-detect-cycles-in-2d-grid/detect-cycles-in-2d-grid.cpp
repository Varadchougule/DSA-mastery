class Solution {
public:

    bool DFScycleDetection(vector<vector<char>>& grid,int i, int j,int parent_i, int parent_j, vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        visited[i][j] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(grid[nx][ny] != grid[i][j]) {
                continue;
            }
            if(!visited[nx][ny]) {
                bool ans = DFScycleDetection(grid,nx,ny,i,j,visited);
                if(ans) {
                    return true;
                }
            }else {
                if(nx != parent_i || ny != parent_j) {
                    return true;
                }
            }
        }
        return false;
    }


    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j]) {
                    bool cycleFound = DFScycleDetection(grid,i,j,-1,-1,visited);
                    if(cycleFound) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};