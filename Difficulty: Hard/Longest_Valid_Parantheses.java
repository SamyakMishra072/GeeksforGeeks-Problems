class Solution {
    static int maxLength(String s) {
        int length = s.length();
        // dp[i] represents the length of the longest valid parentheses ending at index i-1
        int[] dp = new int[length+1];
        int maxLength = 0;
      
        // Start from index 2 since we need at least 2 characters for valid parentheses
        for (int i=2; i<=length; i++) {
            if (s.charAt(i-1) == ')') {
                // Case 1: Previous character is '(', forms a pair "()"
                if (s.charAt(i-2) == '(') {
                    dp[i] = dp[i-2] + 2;
                } 
                // Case 2: Previous character is ')', need to check if we can form a longer sequence
                else {
                    int matchIndex = i-dp[i-1]-1;
                  
                    if (matchIndex > 0 && s.charAt(matchIndex-1) == '(') {
                        dp[i] = dp[i-1] + 2 + dp[matchIndex-1];
                    }
                }
                maxLength = Math.max(maxLength, dp[i]);
            }
        }
      
        return maxLength;
    }
}
