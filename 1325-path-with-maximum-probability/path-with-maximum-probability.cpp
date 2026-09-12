class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        unordered_map<int, list<pair<int, double>>> adj;

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            double w = succProb[i];

            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        vector<double> dist(n, 0.0);


        set<pair<double, int>, greater<pair<double, int>>> st;

        dist[start_node] = 1.0;

        st.insert(make_pair(1.0, start_node));

        while(!st.empty()) {

            auto top = *(st.begin());


            st.erase(st.begin());

            double nodeProbability = top.first;
            int node = top.second;

            if(node == end_node) {
                return nodeProbability;
            }

            for(auto neighbour : adj[node]) {

                int nextNode = neighbour.first;
                double edgeProbability = neighbour.second;

                double newProbability =
                    nodeProbability * edgeProbability;

                if(newProbability > dist[nextNode]) {

                    auto record =
                        st.find(make_pair(dist[nextNode], nextNode));

                    if(record != st.end()) {
                        st.erase(record);
                    }
                    dist[nextNode] = newProbability;
                    st.insert(
                        make_pair(dist[nextNode], nextNode)
                    );
                }
            }
        }

        return 0.0;
    }
};