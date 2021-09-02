class Solution:
  def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
    # greedy and Disjoint Set
    # if (i,j) in pairs and (j,k) in pairs
    # then (i,j,k) can swap for each two index
    # we find all swap sets 
    # sort characters by lexicographically order for each set

    n = len(s)
    fa = [i for i in range(n)]

    # find operation for disjoint set
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
      fa[y] = x

    for u, v in pairs:
      merge(u, v)

    S = {}
    p = {}
    for i in range(n):
      u = find(i)
      if u not in S:
        S[u] = [i]
        p[u] = [s[i]]
      else:
        S[u].append(i)
        p[u].append(s[i])

    ans = []
    for k, v in S.items():
      v.sort()
      p[k].sort()

      ans += [(index, char) for index, char in zip(v, p[k])]

    ans.sort()

    return "".join(v[1] for v in ans)


