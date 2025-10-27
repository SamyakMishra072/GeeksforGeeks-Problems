#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 5; // Number of nodes (example)
    vector<vector<int>> adj(n);

    // Example graph construction
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(n, false);

    cout << "DFS Traversal starting from node 0: ";
    dfs(0, adj, visited);

    return 0;
}
