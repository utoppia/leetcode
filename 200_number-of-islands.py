class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:

    def dfs(i: int, j: int) -> None:
      nonlocal grid, n, m
      grid[i][j] = "0"
      for x, y in [[i+1, j], [i-1, j], [i, j+1], [i, j-1]]:
        if 0 <= x < n and 0 <= y < m and grid[x][y] == "1":
          dfs(x, y)

    ans = 0
    n, m = len(grid), len(grid[0])
    for i in range(n):
      for j in range(m):
        if grid[i][j] == "1":
          dfs(i, j)
          ans += 1
    return ans
