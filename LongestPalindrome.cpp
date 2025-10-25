#include <iostream>
#include <string>
using namespace std;

// Function to find longest palindromic substring
string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, maxLength = 1;

    for (int i = 0; i < n; i++) {
        int low = i - 1;
        int high = i + 1;

        // Expand around center for odd length palindrome
        while (high < n && s[high] == s[i]) high++;
        while (low >= 0 && s[low] == s[i]) low--;

        while (low >= 0 && high < n && s[low] == s[high]) {
            low--;
            high++;
        }

        int length = high - low - 1;
        if (length > maxLength) {
            maxLength = length;
            start = low + 1;
        }
    }
    return s.substr(start, maxLength);
}

int main() {
    string str;
    cin >> str;
    cout << "Longest Palindromic Substring: " << longestPalindrome(str) << endl;
    return 0;
}
