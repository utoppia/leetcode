class Solution:
  def numberOfBoomerangs(self, points: List[List[int]]) -> int:
    def distance(x: List[int], y: List[int]) -> int:
      return (x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2

    n = len(points)

    dist = [[0] * n for _ in range(n)]
    for i in range(n):
      for j in range(n):
        dist[i][j] = distance(points[i], points[j])

    ans = 0
    for i in range(n):
      dist[i].sort()

    for i in range(n):
      j = 1
      while j < n:
        p = j
        while p < n and dist[i][j] == dist[i][p]:
          p += 1
        ans += (p-j) * (p-j-1) // 2
        j = p

    return ans
