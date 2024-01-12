class Solution:
  def climbStairs(self, n: int) -> int:
    # Dynamic Programming
    p = [1,1]
    for i in range(2,n+1):
      p.append(p[i-1] + p[i-2])
    return p[n]
