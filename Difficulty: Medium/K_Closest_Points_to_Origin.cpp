#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given a list of points on a 2D plane, find the k points that are closest to the origin (0,0).
We use Euclidean distance, but to simplify computation, we will use the distance squared.
*/

vector<vector<int>> kClosestPoints(vector<vector<int>>& points, int k) {
    // Step 1: Create a vector to store pairs of (distanceSquared, point)
    vector<pair<int, vector<int>>> distanceWithPoints;

    // Step 2: Calculate distance squared for each point
    for (auto &point : points) {
        int x = point[0];
        int y = point[1];
        int distSquared = x*x + y*y;  // Euclidean distance squared
        distanceWithPoints.push_back({distSquared, point});
    }

    // Step 3: Sort the points based on their distance from the origin
    sort(distanceWithPoints.begin(), distanceWithPoints.end());

    // Step 4: Collect the first k points (smallest distances) into the result
    vector<vector<int>> result;
    for (int i = 0; i < k; i++) {
        result.push_back(distanceWithPoints[i].second);
    }

    return result;
}

int main() {
    // Example input
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    // Get k closest points to origin
    vector<vector<int>> closestPoints = kClosestPoints(points, k);

    // Print the result
    cout << "The " << k << " closest points to origin are:\n";
    for (auto &point : closestPoints) {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}
