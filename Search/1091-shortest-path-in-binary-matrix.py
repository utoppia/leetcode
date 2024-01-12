class Solution:
  def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:

    n, m = len(grid), len(grid[0])

    if grid[0][0] or grid[n-1][m-1]:
      return -1

    if n == m == 1:
      return 1

    q = [(0, 0, 1)]
    grid[0][0] = 1

    while q:
      u, v, dep = q.pop(0)

      for x, y in [[u+1,v], [u-1,v], [u+1,v-1], [u+1,v+1], [u-1,v+1], [u-1,v-1], [u,v+1], [u,v-1]]:
        if 0 <= x < n and 0 <= y < m and grid[x][y] == 0:
          q.append((x, y, dep+1))
          grid[x][y] = 1

          if x == n-1 and y == m-1:
            return dep + 1

    return -1

