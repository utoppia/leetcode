class Solution:
  def isBipartite(self, graph: List[List[int]]) -> bool:
    # Disjoint Set

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    def union(x: int, y: int) -> None:
      nonlocal fa
      fx = find(x)
      fy = find(y)
      fa[fx] = fy

    n = len(graph)
    fa = [i for i in range(n)]

    for u in range(n):
      fu = find(u)
      for v in graph[u]:
        if find(v) == fu:
          return False
      if graph[u]:
        fv = graph[u][0]
        for v in graph[u][1:]:
          union(fv, v)
    return True
