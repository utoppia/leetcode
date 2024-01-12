class Solution:
  def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

    g = obstacleGrid
    n, m = len(g), len(g[0])

    dp = [[0] * m for _ in range(n)]

    dp[0][0] = 1 if g[0][0] != 1 else 0
    for i in range(1, m):
      if g[0][i] == 1:
        dp[0][i] = 0
      else:
        dp[0][i] = dp[0][i-1]

    for i in range(1, n):
      for j in range(0, m):
        if g[i][j] == 1:
          dp[i][j] = 0
          continue

        if i > 0:
          dp[i][j] += dp[i-1][j]
        if j > 0:
          dp[i][j] += dp[i][j-1]

    return dp[n-1][m-1]
