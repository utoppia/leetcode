class Solution:
  def longestPalindromeSubseq(self, s: str) -> int:
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    for i in range(n):
      dp[i][i] = 1

    for l in range(1, n):
      for i in range(0, n-1):
        j = i + l
        if j >= n:
          break

        dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        if s[i] == s[j]:
          dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2)

    return dp[0][n-1]
