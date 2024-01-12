class Solution:
  def numSquares(self, n: int) -> int:
    a = [i ** 2 for i in range(1, 100)]
    dp = [i for i in range(n + 1)]
    for j in a:
      for i in range(j, n + 1):
        dp[i] = min(dp[i], dp[i-j] + 1)

    return dp[n]
