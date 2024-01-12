class Solution:
  def numTrees(self, n: int) -> int:
    dp = [1, 1, 2]
    for i in range(3, n + 1):
      s = 0
      for j in range(1, i + 1):
        s += dp[j - 1] * dp[i - j]
      dp.append(s)

    return dp[n]
