#include <iostream>
#include <vector>
#include <numeric>

long long findMissingElement(const std::vector<int>& arr) {
    long long n = arr.size() + 1;
    long long expectedSum = n * (n + 1) / 2;
    long long actualSum = 0;
    for (int element : arr) {
        actualSum += element;
    }
    return expectedSum - actualSum;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 5};
    std::cout << "Input: [1, 2, 3, 5], Missing: " << findMissingElement(arr1) << std::endl; 
    std::vector<int> arr2 = {8, 2, 4, 5, 3, 7, 1};
    std::cout << "Input: [8, 2, 4, 5, 3, 7, 1], Missing: " << findMissingElement(arr2) << std::endl;
    return 0;
}