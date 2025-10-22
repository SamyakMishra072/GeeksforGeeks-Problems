#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Traversal of a simple graph
void bfs(int V, vector<vector<int>> &adj) {
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    cout << "BFS Traversal starting from node 0: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;  // number of vertices
    vector<vector<int>> adj = {
        {1, 2}, {0, 3, 4}, {0}, {1}, {1}
    };

    bfs(V, adj);
    return 0;
}
