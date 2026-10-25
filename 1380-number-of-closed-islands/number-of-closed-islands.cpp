class Solution {
public:
    bool DFS(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>>& visited) {

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size()) {
            return false;
        }

        if (grid[i][j] == 1 || visited[i][j]) {
            return true;
        }

        visited[i][j] = true;

        bool down = DFS(grid, i + 1, j, visited);
        bool up = DFS(grid, i - 1, j, visited);
        bool right = DFS(grid, i, j + 1, visited);
        bool left = DFS(grid, i, j - 1, visited);

        return down && up && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && grid[i][j] == 0){
                    if(DFS(grid,i,j,visited)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};