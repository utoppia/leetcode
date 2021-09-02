class Solution:
  def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
    # Disjoint Set

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] == -1:
        return x
      fa[x] = find(fa[x])
      return fa[x]

    n = len(edges)
    fa = [-1] * n

    for u, v in edges:
      x = find(u-1)
      y = find(v-1)
      if x == y:
        return [u, v]
      fa[x] = y

