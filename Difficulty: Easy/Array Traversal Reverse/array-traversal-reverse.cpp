class Solution {
  public:
    void arrayTraversalReverse(int numbers[], int size) {
        for (int i = size - 1; i >= 0; i--) {
            cout << numbers[i] << " ";
        }
    }
};
