class Solution:
  def equationsPossible(self, equations: List[str]) -> bool:
    # Disjoint Set

    fa = {}
    conditions = []
    judges = []
    for e in equations:
      if e[1] == '!':
        judges.append((e[0], e[3]))
      else:
        conditions.append((e[0], e[3]))
      if e[0] not in fa:
        fa[e[0]] = e[0]
      if e[3] not in fa:
        fa[e[3]] = e[3]

    def find(x: str) -> str:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    for a, b in conditions:
      x = find(a)
      y = find(b)
      fa[x] = y

    for a, b in judges:
      x = find(a)
      y = find(b)
      if x == y:
        return False
    return True

