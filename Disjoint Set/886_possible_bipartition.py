class Solution:
  def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
    # Disjoint Set

    # init
    adj = [[] for _ in range(n)]
    for u, v in dislikes:
      adj[u-1].append(v-1)
      adj[v-1].append(u-1)

    fa = [i for i in range(n)]

    # Find operation for disjoint set
    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    # merge operation for disjoint set
    def merge(x: int, y: int) -> None:
      nonlocal fa
      x = find(x)
      y = find(y)
      fa[x] = y

    for u in range(n):
      fu = find(u)
      for v in adj[u]:
        if find(v) == fu:
          return False

      if adj[u]:
        v = adj[u][0]
        for k in adj[u][1:]:
          merge(v, k)
    return True
