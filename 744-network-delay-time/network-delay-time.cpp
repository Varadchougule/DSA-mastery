class Solution {
public:

    void Dijkstra(
        int src,
        set<pair<int,int>>& st,
        vector<int>& dist,
        unordered_map<int,list<pair<int,int>>>& adj
    ) {
        
        dist[src] = 0;
        st.insert({0, src});

        while(!st.empty()) {

            auto top = *(st.begin());
            st.erase(st.begin());

            int nodeDistance = top.first;
            int node = top.second;

            for(auto neighbour : adj[node]) {

                int neighbourNode = neighbour.first;
                int weight = neighbour.second;

                if(nodeDistance + weight < dist[neighbourNode]) {

                    auto record = st.find(
                        {dist[neighbourNode], neighbourNode}
                    );

                    if(record != st.end()) {
                        st.erase(record);
                    }

                    dist[neighbourNode] = nodeDistance + weight;

                    st.insert({
                        dist[neighbourNode],
                        neighbourNode
                    });
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,list<pair<int,int>>> adj;

        for(int i = 0; i < times.size(); i++) {

            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        set<pair<int,int>> st;

        vector<int> dist(n + 1, INT_MAX);

        Dijkstra(k, st, dist, adj);

        int time = 0;

        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            }

            time = max(time, dist[i]);
        }

        return time;
    }
};