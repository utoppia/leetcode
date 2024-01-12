class Solution:
  def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
    # Disjoint Set
    fa = {}
    value = {}

    def find(x: str) -> str:
      nonlocal fa
      nonlocal value
      if x not in fa:
        return x
      if fa[x] == -1:
        return x
      else:
        y = find(fa[x])
        value[x] *= value[fa[x]]
        fa[x] = y
        return fa[x]

    for [x, y], k in zip(equations, values):
      if x not in fa:
        fa[x] = -1
        value[x] = 1
      if y not in fa:
        fa[y] = -1
        value[y] = 1
      
      dx = find(x)
      dy = find(y)
      if dx == dy:
        continue
      value[dx] = value[y] * k / value[x]
      fa[dx] = dy

    ans = []
    for x, y in queries:
      fx = find(x)
      fy = find(y)
      if fx != fy or fx not in value:
        ans.append(-1.0)
      else:
        ans.append(value[x]/value[y])
    return ans

