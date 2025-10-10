class Solution {
public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Create an adjacency list for the graph
        vector<vector<int>> adj(V);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        // 'disc' stores discovery times of visited vertices
        // 'low' stores the lowest discovery time reachable from a vertex
        vector<int> disc(V, -1), low(V), res;

        // 'ap' marks articulation points (true if vertex is one)
        // 'vis' keeps track of visited nodes
        vector<bool> ap(V), vis(V);
        
        int time = 0; // Timer for discovery times

        // Depth First Search (DFS) function (recursive)
        function<void(int, int)> dfs = [&](int u, int p) {
            vis[u] = true;               // Mark current node as visited
            disc[u] = low[u] = time++;   // Initialize discovery and low value
            int children = 0;            // Count of children in DFS Tree

            // Explore all adjacent vertices
            for (int v : adj[u]) {
                if (v == p) continue;    // Ignore the edge to parent node

                if (!vis[v]) {           // If 'v' is not visited, recurse for it
                    dfs(v, u);
                    low[u] = min(low[u], low[v]); // Update low value after DFS call

                    // Condition 1: If u is not root and low[v] >= disc[u],
                    // then u is an articulation point
                    if (p != -1 && low[v] >= disc[u])
                        ap[u] = true;

                    ++children; // Count children
                } 
                else {
                    // Update low value of u for back edge
                    low[u] = min(low[u], disc[v]);
                }
            }

            // Condition 2: If u is root of DFS tree and has more than one child
            if (p == -1 && children > 1)
                ap[u] = true;
        };

        // Run DFS for each unvisited node (handles disconnected graphs)
        for (int i = 0; i < V; ++i)
            if (!vis[i]) dfs(i, -1);

        // Collect all articulation points
        for (int i = 0; i < V; ++i)
            if (ap[i]) res.push_back(i);

        // If no articulation points, return {-1}
        return res.empty() ? vector<int>{-1} : res;
    }
};
