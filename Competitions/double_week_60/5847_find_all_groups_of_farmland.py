class Solution:
  def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
    dxy = [[1,0], [-1,0], [0,1], [0,-1]]

    n, m = len(land), len(land[0])

    ret = []
    for i in range(n):
      for j in range(m):
        if land[i][j] == 1:
          ans = [i,j,i,j]
          queue = [(i,j)]
          land[i][j] = 0
          while queue:
            u, v = queue.pop(0)
            for dx, dy in dxy:
              x, y = u + dx, v + dy
              if x >= 0 and x < n and y >= 0 and y < m and land[x][y]:
                if x <= ans[0] and y <= ans[1]:
                  ans[0], ans[1] = x, y
                if x >= ans[2] and y >= ans[3]:
                  ans[2], ans[3] = x, y
                land[x][y] = 0
                queue.append((x, y))
          ret.append(ans)
    return ret
