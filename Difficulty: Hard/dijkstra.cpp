#include <bits/stdc++.h>
using namespace std;

/*
 * Enhanced Dijkstra's Algorithm Implementation
 * Time Complexity: O((V + E) log V) where V is vertices and E is edges
 * Space Complexity: O(V)
 * 
 * Features:
 * - Shortest path distances
 * - Path reconstruction
 * - Support for directed weighted graphs
 * - Comprehensive error handling
 * - Multiple test cases
 */

const int INF = 1e9;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

class Graph {
private:
    int V;  // number of vertices
    vector<vector<Edge>> adj;  // adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int from, int to, int weight, bool isDirected = false) {
        if (from < 0 || from >= V || to < 0 || to >= V) {
            throw runtime_error("Invalid vertex index");
        }
        if (weight < 0) {
            throw runtime_error("Negative weight not allowed in Dijkstra's algorithm");
        }
        adj[from].emplace_back(to, weight);
        if (!isDirected) {
            adj[to].emplace_back(from, weight);
        }
    }

    pair<vector<int>, vector<int>> dijkstra(int source) {
        if (source < 0 || source >= V) {
            throw runtime_error("Invalid source vertex");
        }

        vector<int> dist(V, INF);  // distances
        vector<int> parent(V, -1);  // for path reconstruction
        dist[source] = 0;

        // Min-heap: {distance, vertex}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;  // Skip if we've found a better path

            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        return {dist, parent};
    }

    void printPath(const vector<int>& parent, int target) {
        if (target == -1) return;
        
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        
        reverse(path.begin(), path.end());
        
        cout << "Path: ";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " → ";
        }
        cout << "\n";
    }
};

// Helper function to create and test a sample graph
void testCase1() {
    cout << "\nTest Case 1: Basic undirected graph\n";
    cout << "===============================\n";
    
    try {
        Graph g(9);
        // Adding edges (from, to, weight, isDirected)
        g.addEdge(0, 1, 4);
        g.addEdge(1, 2, 8);
        g.addEdge(2, 3, 7);
        g.addEdge(3, 4, 9);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(7, 0, 8);
        g.addEdge(7, 1, 11);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 5, 14);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);

        int source = 0;
        auto [distances, parents] = g.dijkstra(source);

        cout << "Shortest distances from node " << source << ":\n";
        for (int i = 0; i < distances.size(); ++i) {
            cout << "To " << i << ": " << distances[i] << "\n";
            g.printPath(parents, i);
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Test case with a directed graph
void testCase2() {
    cout << "\nTest Case 2: Directed graph\n";
    cout << "========================\n";
    
    try {
        Graph g(5);
        // Adding directed edges (from, to, weight, isDirected=true)
        g.addEdge(0, 1, 5, true);
        g.addEdge(0, 2, 3, true);
        g.addEdge(1, 3, 6, true);
        g.addEdge(1, 2, 2, true);
        g.addEdge(2, 4, 4, true);
        g.addEdge(2, 3, 7, true);
        g.addEdge(3, 4, 1, true);

        int source = 0;
        auto [distances, parents] = g.dijkstra(source);

        cout << "Shortest distances from node " << source << ":\n";
        for (int i = 0; i < distances.size(); ++i) {
            cout << "To " << i << ": " << distances[i] << "\n";
            g.printPath(parents, i);
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    try {
        testCase1();  // Test with undirected graph
        testCase2();  // Test with directed graph
    } catch (const exception& e) {
        cout << "Fatal error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
