class Solution:
  def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
    n, m = len(mat), len(mat[0])
    q = [(i, j) for i in range(n) for j in range(m) if mat[i][j] == 0]
    dist = [[0] * m for _ in range(n)]

    visited = set(q)

    while q:
      u, v = q.pop(0)
      for x, y in [(u - 1, v), (u + 1, v), (u, v + 1), (u, v - 1)]:
        if 0 <= x < n and 0 <= y < m and (x, y) not in visited:
          q.append((x, y))
          dist[x][y] = dist[u][v] + 1
          visited.add((x, y))
    return dist
