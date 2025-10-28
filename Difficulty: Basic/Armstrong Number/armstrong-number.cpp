#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = (n == 0) ? 1 : (int)log10(n) + 1;
        long long sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += (long long)pow(d, digits);
            n /= 10;
        }
        return sum == original;
    }
};
