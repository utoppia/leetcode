class Solution:
  def countServers(self, grid: List[List[int]]) -> int:
    # Disjoint Set

    m, n = len(grid), len(grid[0])

    keys = [[-1] * n for _ in range(m)]

    cnt = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j]:
          keys[i][j] = cnt
          cnt += 1

    fa = [i for i in range(cnt)]
    weight = [1 for _ in range(cnt)]

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    def merge(x: int, y: int) -> None:
      nonlocal fa
      nonlocal weight
      x = find(x)
      y = find(y)
      fa[y] = x
      weight[x] += weight[y]

    for i in range(m):
      tmp = []
      for j in range(n):
        if grid[i][j]:
          tmp.append(keys[i][j])

      for j in range(len(tmp)):
        for k in range(j+1, len(tmp)):
          merge(tmp[j], tmp[k])
      
    for i in range(n):
      tmp = []
      for j in range(m):
        if grid[j][i]:
          tmp.append(keys[j][i])

      for j in range(len(tmp)):
        for k in range(j+1, len(tmp)):
          merge(tmp[j], tmp[k])

    ans = cnt
    for i in range(cnt):
      if weight[find(i)] == 1:
        ans -= 1
    return ans

