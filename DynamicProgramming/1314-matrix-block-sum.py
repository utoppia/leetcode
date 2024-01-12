class Solution:
  def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
    # prefix sum
    # let pre[i][j] = sum(mat[u][v]) where 0 <= u <= i and 0 <= v <= j
    # therefore pre[i][j] = mat[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]
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

    # ans[i][j][i][j] = pre[i+k][j+k] - pre[i-k-1][j+k] - pre[i+k][j-k-1] + pre[i-k-1][j-k-1]

    ans = [[0] * m for _ in range(n)]
    for i in range(n):
      for j in range(m):
        u = min(n-1, i+k)
        v = min(m-1, j+k)
        ans[i][j] = pre[u][v]
        if i - k >= 1:
          ans[i][j] -= pre[i-k-1][v]
        if j - k >= 1:
          ans[i][j] -= pre[u][j-k-1]

        if i - k >= 1 and j -k >= 1:
          ans[i][j] += pre[i-k-1][j-k-1]

    return ans

