from math import gcd
class Solution:
  def maxPoints(self, points: List[List[int]]) -> int:

    def polar(u: List[int], v: List[int]) -> (int, int):
      x = v[0] - u[0]
      y = v[1] - u[1]
      if x * y >= 0:
        x, y = abs(x), abs(y)
      if x * y < 0:
        x, y = -abs(x), abs(y)

      if x == 0:
        return (0, 1)
      if y == 0:
        return (1, 0)

      m = gcd(x, y)
      return (x//m, y//m)
    
    if not points:
      return 0

    ans = 1

    n = len(points)
    
    for i in range(n):
      k = defaultdict(int)
      for j in range(i+1, n):
        k[polar(points[i], points[j])] += 1
      if k:
        tmp = max([val for val in k.values()])
        ans = max(ans, tmp + 1)

    return ans




