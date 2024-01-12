class Solution:
  def findCircleNum(self, isConnected: List[List[int]]) -> int:
    # Disjoint Set

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] == -1:
        return x
      fa[x] = find(fa[x])
      return fa[x]

    n = len(isConnected)
    fa = [-1] * n

    ans = n

    for i in range(n):
      for j in range(i+1, n):
        if isConnected[i][j]:
          x = find(i)
          y = find(j)
          if x != y:
            ans -= 1
            fa[x] = y
    return ans
