class Solution:
  def orangesRotting(self, grid: List[List[int]]) -> int:
    n, m = len(grid), len(grid[0])
    q = [(i, j) for i in range(n) for j in range(m) if grid[i][j] == 2]
    rot = [[0] * m for _ in range(n)]

    seen = set(q)
    ans = 0
    while q:
      u, v = q.pop(0)
      for x, y in [(u-1, v), (u+1, v), (u, v-1), (u, v+1)]:
        if 0 <= x < n and 0 <= y < m and grid[x][y] and (x, y) not in seen:
          rot[x][y] = rot[u][v] + 1
          seen.add((x, y))
          q.append((x, y))
          grid[x][y] = 2
          ans = max(ans, rot[x][y])
    
    if len([0 for i in range(n) for j in range(m) if grid[i][j]==1]):
      return -1
    return ans

