class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<bool> visited(n, false);
        vector<int> GraphColour(n, -1);

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                continue;
            }

            queue<int> q;

            q.push(i);
            visited[i] = true;
            GraphColour[i] = 0;

            while(!q.empty()) {

                int top = q.front();
                q.pop();

                for(auto neighbour : graph[top]) {
                    if(!visited[neighbour]) {

                        visited[neighbour] = true;

                        q.push(neighbour);
                        if(GraphColour[top] == 0) {
                            GraphColour[neighbour] = 1;
                        }
                        else {
                            GraphColour[neighbour] = 0;
                        }
                    }
                    else {
                        if(GraphColour[top] == GraphColour[neighbour]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};