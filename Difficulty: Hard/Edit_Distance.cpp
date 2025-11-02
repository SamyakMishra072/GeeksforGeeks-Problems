class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                
                if (i == 0)
                    dp[i][j] = j;
                
                else if (j == 0)
                    dp[i][j] = i;
                
                // If characters match, no new operation required
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                // If different, consider all three operations
                else
                    dp[i][j] = 1 + min({dp[i][j - 1],    // Insert
                                       dp[i - 1][j],    // Remove
                                       dp[i - 1][j - 1] // Replace
                                      });
            }
        }
        
        return dp[m][n];
        
    }
};
