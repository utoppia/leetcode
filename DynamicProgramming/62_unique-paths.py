class Solution:
  def uniquePaths(self, m: int, n: int) -> int:

    dp = [1] * n

    for _ in range(m-1):
      for i in range(1, n):
        dp[i] += dp[i-1]

    return dp[n-1]
