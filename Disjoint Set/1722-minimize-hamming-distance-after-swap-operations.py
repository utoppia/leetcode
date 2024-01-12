class Solution:
  def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
    # Disjoint Set

    n = len(source)

    fa = [i for i in range(n)]

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    for u, v in allowedSwaps:
      u = find(u)
      v = find(v)
      fa[u] = v

    S = {}

    for i in range(n):
      x = find(i)
      if x not in S:
        S[x] = [i]
      else:
        S[x].append(i)

    ans = 0
    for index in S.values():
      s1 = collections.Counter([source[i] for i in index])
      s2 = collections.Counter([target[i] for i in index])
      for k, v in s1.items():
        if k not in s2:
          ans += v
        elif v > s2[k]:
          ans += v - s2[k]
      
    return ans
