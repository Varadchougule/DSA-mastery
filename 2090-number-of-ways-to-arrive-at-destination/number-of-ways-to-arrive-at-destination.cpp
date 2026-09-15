class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int, list<pair<int,int>>> adj;

        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        set<pair<long long,int>> st;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        int src = 0;

        dist[src] = 0;
        ways[src] = 1;

        st.insert({0, src});

        int MOD = 1e9 + 7;

        while(!st.empty()) {

            auto top = *(st.begin());
            st.erase(st.begin());

            long long nodeDistance = top.first;
            int node = top.second;

            for(auto neighbour : adj[node]) {

                int nextNode = neighbour.first;
                int weight = neighbour.second;

                long long newDistance = nodeDistance + weight;

                // Found a shorter path
                if(newDistance < dist[nextNode]) {

                    auto record = st.find(
                        {dist[nextNode], nextNode}
                    );

                    if(record != st.end()) {
                        st.erase(record);
                    }

                    dist[nextNode] = newDistance;

                    ways[nextNode] = ways[node];

                    st.insert(
                        {dist[nextNode], nextNode}
                    );
                }

                // Found another shortest path
                else if(newDistance == dist[nextNode]) {

                    ways[nextNode] =
                        (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};