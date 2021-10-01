class Solution:
  def destCity(self, paths: List[List[str]]) -> str:
    k = {}
    for u, v in paths:
      if u not in k:
        k[u] = 1
      else:
        k[u] += 1
      
      if v not in k:
        k[v] = 0

    for name, val in k.items():
      if val == 0:
        return name
