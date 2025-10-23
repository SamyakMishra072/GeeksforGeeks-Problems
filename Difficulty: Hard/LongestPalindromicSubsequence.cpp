#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Longest Palindromic Subsequence
// Problem: Find the length of the longest subsequence of a string that is also a palindrome
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class LongestPalindromicSubsequence {
public:
    // Function to find the length of the longest palindromic subsequence
    int longestPalindromeSubseq(const string &s) {
        int n = s.size();
        
        // dp[i][j] stores length of longest palindromic subsequence in substring s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Build the dp table for substrings of increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Final result is the longest palindrome subsequence length for the full string
        return dp[0][n - 1];
    }
};

int main() {
    LongestPalindromicSubsequence lps;
    string s = "bbbab";
    int result = lps.longestPalindromeSubseq(s);
    cout << "Length of Longest Palindromic Subsequence: " << result << endl;
    return 0;
}
