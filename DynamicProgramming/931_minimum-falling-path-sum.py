class Solution:
  def minFallingPathSum(self, matrix: List[List[int]]) -> int:
    n, m = len(matrix), len(matrix[0])

    dp = [[0] * m for _ in range(n)]

    for i in range(m):
      dp[0][i] = matrix[0][i]

    for i in range(1, n):
      for j in range(m):
        dp[i][j] = dp[i-1][j] + matrix[i][j]

        if j > 0:
          dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j])

        if j < n - 1:
          dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j])

    ans = dp[n-1][0]
    for j in range(m):
      ans = min(ans, dp[n-1][j])

    return ans
