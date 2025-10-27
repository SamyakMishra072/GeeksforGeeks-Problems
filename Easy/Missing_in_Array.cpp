#include <bits/stdc++.h>
using namespace std;

// Function to find missing number
int findMissing(vector<int>& arr) {
    int n = arr.size() + 1;  // Full range is 1 to n
    int xor_all = 0;
    
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor_all ^= i;
    }
    
    // XOR with array elements (cancels out present numbers)
    for (int num : arr) {
        xor_all ^= num;
    }
    
    return xor_all;
}

int main() {
    // Test cases from the problem
    vector<int> arr1 = {1, 2, 3, 5};
    cout << "Missing: " << findMissing(arr1) << endl;  // Output: 4
    
    vector<int> arr2 = {8, 2, 4, 5, 3, 7, 1};
    cout << "Missing: " << findMissing(arr2) << endl;  // Output: 6
    
    vector<int> arr3 = {1};
    cout << "Missing: " << findMissing(arr3) << endl;  // Output: 2
    
    return 0;
}