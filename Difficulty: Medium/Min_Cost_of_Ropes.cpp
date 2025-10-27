// Problem: Minimum Cost of Ropes
// Topic: Greedy / Heap
// Difficulty: Medium
// Language: C++
//
// Approach:
// Use a Min-Heap (Priority Queue) to always connect the two smallest ropes first.
// Each time two ropes are connected, their combined length is added back to the heap.
// The sum of all connection costs gives the minimum total cost.

#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum cost of connecting all ropes
long long minCost(vector<long long>& ropes) {
    // Min-heap to store rope lengths
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(ropes.begin(), ropes.end());

    long long totalCost = 0;

    // Continue until all ropes are connected into one
    while (minHeap.size() > 1) {
        // Extract the two smallest ropes
        long long first = minHeap.top(); 
        minHeap.pop();

        long long second = minHeap.top();
        minHeap.pop();

        // Connect them (add their lengths)
        long long cost = first + second;
        totalCost += cost;

        // Push the new combined rope back into the heap
        minHeap.push(cost);
    }

    return totalCost;
}

// Driver code for testing
int main() {
    vector<long long> ropes = {4, 3, 2, 6};
    cout << "Minimum total cost to connect ropes: " << minCost(ropes) << endl;
    return 0;
}
