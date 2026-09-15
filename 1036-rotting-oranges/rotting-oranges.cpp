class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;

        int rows = grid.size();
        int cols = grid[0].size();

        int fresh = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int Minutes = 0;
        while(!q.empty() && fresh > 0) {

            int size = q.size();
            for(int k = 0; k < size; k++) {

                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < rows &&
                       ny >= 0 && ny < cols &&
                       grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;

                        fresh--;

                        q.push({nx, ny});
                    }
                }
            }

            Minutes++;
        }

        if(fresh > 0) {
            return -1;
        }

        return Minutes;
    }
};