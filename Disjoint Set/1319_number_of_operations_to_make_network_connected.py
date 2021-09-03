class Solution:
  def makeConnected(self, n: int, connections: List[List[int]]) -> int:
    # Disjoint Set

    fa = [i for i in range(n)]

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    cnt = n - 1
    extra = 0

    for u, v in connections:
      a = find(u)
      b = find(v)
      if a == b:
        extra += 1
      else:
        cnt -= 1
        fa[a] = b

    if extra >= cnt:
      return cnt
    else:
      return -1
