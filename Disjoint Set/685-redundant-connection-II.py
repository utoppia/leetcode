class Solution:
  def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
    # Disjoint Set

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    n = len(edges)
    fa = [i for i in range(n)]
    parent = [-1] * n

    ans = None
    isCircle = False
    tmp = None

    for u, v in edges:
      x = find(u-1)
      y = find(v-1)
      if y != v - 1:
        ans = [u, v]
        continue
      
      parent[v-1] = u
      if x == y:
        isCircle = True
        tmp = [u, v]
        continue

      fa[y] = x

    if not ans:
      return tmp

    if isCircle:
      return [parent[ans[1]-1], ans[1]]

    return ans

