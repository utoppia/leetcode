class NumMatrix:

  def __init__(self, matrix: List[List[int]]):
    mat = matrix
    n, m = len(mat), len(mat[0])
    pre = [[0] * m for _ in range(n)]

    for i in range(n):
      for j in range(m):
        pre[i][j] = mat[i][j]
        if i > 0:
          pre[i][j] += pre[i-1][j]
        if j > 0:
          pre[i][j] += pre[i][j-1]
        if i > 0 and j > 0:
          pre[i][j] -= pre[i-1][j-1]
    self.pre = pre


  def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
    u, v, x, y = row1, col1, row2, col2
    pre = self.pre

    ans = pre[x][y]
    if u >= 1:
      ans -= pre[u-1][y]
    if v >= 1:
      ans -= pre[x][v-1]
    if u >= 1 and v >= 1:
      ans += pre[u-1][v-1]

    return ans
