class Solution:
  def integerBreak(self, n: int) -> int:

    dp = [i-1 for i in range(n + 1)]
    dp[1] = 1

    for i in range(n+1):
      for j in range(1, i):
        dp[i] = max(dp[i], max(dp[j], j) * max(dp[i-j], i-j))

    return dp[n]
