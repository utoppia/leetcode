class DisjointSet:
  def __init__(self, m: int, n: int, grid: List[List[int]]) -> None:
    self.total = m * n
    self.fa = [i for i in range(self.total + 1)]
    self.w = [1] * (self.total + 1)
    for i in range(m):
      for j in range(n):
        if grid[i][j]:
          self.add(i, i * n + j)

  def add(self, x: int, u:int) -> None:
    if x == 0:
      self.fa[u] = self.total
      self.w[self.total] += 1

  def find(self, x: int) -> int:
    if self.fa[x] != x:
      self.fa[x] = self.find(self.fa[x])
    return self.fa[x]

  def merge(self, x: int, y: int) -> int:
    x = self.find(x)
    y = self.find(y)

    if x == y:
      return

    if x == self.total: 
      # x connect to ceil
      self.w[x] += self.w[y]
      self.fa[y] = x
      return

    self.w[y] += self.w[x]
    self.fa[x] = y

  def size(self):
    return self.w[self.total]

class Solution:
  def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
    # Disjoint Set

    def valid(i: int, j: int) -> bool:
      nonlocal n, m
      if i >= 0 and i < m and j >= 0 and j < n:
        return True
      return False

    dxy = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    m, n = len(grid), len(grid[0])
    for u, v in hits:
      grid[u][v] -= 1

    s = DisjointSet(m, n, grid)

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1:
          for dx, dy in dxy:
            x, y = i + dx, j + dy
            if valid(x, y) and grid[x][y] == 1:
              s.merge(i*n+j, x*n+y)

    ans = []
    for u, v in hits[::-1]:

      grid[u][v] += 1

      if grid[u][v] == 0:
        # (u, v) is not a brick
        ans.append(0)
        continue

      pre_size = s.size()

      # add this brick to disjoint set
      s.add(u, u*n+v)

      for dx, dy in dxy:
        x, y = u + dx, v + dy
        if valid(x, y) and grid[x][y] == 1:
          # merge this two set
          s.merge(u*n+v, x*n+y)
      
      ans.append(max(0,s.size() - pre_size - 1))

    ans.reverse()
    return ans

