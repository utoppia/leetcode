class Solution:
  def minPathSum(self, grid: List[List[int]]) -> int:
    n, m = len(grid), len(grid[0])
    dp = [grid[0][i] for i in range(m)]
    for j in range(1, m):
      dp[j] += dp[j-1]

    for i in range(1, n):
      for j in range(m):
        dp[j] += grid[i][j]
        if j >= 1:
          dp[j] = min(dp[j], dp[j-1] + grid[i][j])

    return dp[m-1]
