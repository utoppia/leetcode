class Solution:
  def closedIsland(self, grid: List[List[int]]) -> int: 
    # simillar with 1020 number of enclaves

    def count(i: int, j: int) -> int:
      dxy = [[1, 0], [-1, 0], [0, 1], [0, -1]]
      flag = True
      queue = [(i, j)]
      nonlocal visited
      nonlocal grid
      visited[i][j] = True
      while queue:
        i, j = queue.pop(0)
        for dx, dy in dxy:
          u = i + dx
          v = j + dy
          if u < 0 or u >= n or v < 0 or v >= m:
            flag = False
            continue
          if visited[u][v] or grid[u][v] == 1:
            continue
          visited[u][v] = True
          queue.append((u, v))
      if flag:
        return 1
      else:
        return 0

    n, m = len(grid), len(grid[0])

    visited = [[False] * m for _ in range(n)]

    ans = 0
    for i in range(n):
      for j in range(m):
        if grid[i][j] == 0 and not visited[i][j]:
          ans += count(i, j)
    return ans
