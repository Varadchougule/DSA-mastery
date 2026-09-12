class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, list<pair<int,int>>> adj;

        for(int i = 0; i < flights.size(); i++) {

            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        set<tuple<int,int,int>> st;

        // dist[node][stops]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;

        st.insert({0, src, 0});

        while(!st.empty()) {

            auto top = *(st.begin());
            st.erase(st.begin());

            int cost = get<0>(top);
            int node = get<1>(top);
            int stops = get<2>(top);

            if(node == dst) {
                return cost;
            }

            if(stops > k) {
                continue;
            }

            for(auto neighbour : adj[node]) {

                int nextNode = neighbour.first;
                int price = neighbour.second;

                int newCost = cost + price;
                int newStops = stops + 1;

                if(newCost < dist[nextNode][newStops]) {

                    dist[nextNode][newStops] = newCost;

                    st.insert({
                        newCost,
                        nextNode,
                        newStops
                    });
                }
            }
        }

        return -1;
    }
};