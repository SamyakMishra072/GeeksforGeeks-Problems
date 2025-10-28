#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindromeNumber(long long x) {
        if (x < 0) return false; // negative numbers are not palindromes
        long long original = x;
        long long rev = 0;
        while (x > 0) {
            int d = (int)(x % 10);
            if (rev > (LLONG_MAX - d) / 10) {
                return false; // overflow guard
            }
            rev = rev * 10 + d;
            x /= 10;
        }
        return rev == original;
    }
};
