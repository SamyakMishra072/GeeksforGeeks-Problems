class Solution {
public:
    int total_cost;

    int tsp(vector<vector<int>> &cost) {
        int n = cost.size();
        vector<int> nodes;
        
        // Exclude 0 as starting point
        for (int i = 1; i < n; i++)
            nodes.push_back(i);

        int minCost = INT_MAX;

        // Generate all permutations
        do {
            int currCost = 0;
            int currNode = 0;

            // Calculate current route cost
            for (int i = 0; i < nodes.size(); i++) {
                currCost += cost[currNode][nodes[i]];
                currNode = nodes[i];
            }

            // Add cost to return back to source
            currCost += cost[currNode][0];

            minCost = min(minCost, currCost);

        } while (next_permutation(nodes.begin(), nodes.end()));

        return minCost;
    }
};
