class Solution:
  def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
    dxy = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    n, m = len(grid), len(grid[0])
    ans = 0
    for i in range(n):
      for j in range(m):
        if grid[i][j]:
          queue = [(i, j)]
          cur = 1
          grid[i][j] = 0
          while queue:
            u, v = queue.pop(0)
            for dx, dy in dxy:
              x, y = u + dx, v + dy
              if x >= 0 and x < n and y >=0 and y < m and grid[x][y]==1:
                grid[x][y] = 0
                cur += 1
                queue.append((x, y))
            ans = max(ans, cur)
    return ans
              
