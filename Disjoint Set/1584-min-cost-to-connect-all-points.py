class Solution:
  def minCostConnectPoints(self, points: List[List[int]]) -> int:
    # Disjoint Set

    adj = []
    for i in range(len(points)):
      p = points[i]
      for j in range(i+1, len(points)):
        q = points[j]
        adj.append((abs(p[0]-q[0])+abs(p[1]-q[1]), i, j))

    adj.sort()

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    fa = [i for i in range(len(points))]

    cnt = len(points) - 1
    ans = 0

    while cnt:
      v, a, b = adj.pop(0)
      a = find(a)
      b = find(b)
      if a != b:
        ans += v
        fa[a] = b
        cnt -= 1

    return ans
