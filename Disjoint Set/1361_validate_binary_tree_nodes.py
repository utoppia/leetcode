class Solution:
  def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
    # Disjoint Set

    fa = [i for i in range(n)]

    # find operation for disjoint set
    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    edge = n
    for child in [leftChild, rightChild]:
      for u, v in enumerate(child):
        if v == -1:
          continue
        
        x = find(u)
        y = find(v)

        if x == y:
          # circle
          return False

        if y != v:
          # node v has been pointed
          return False

        fa[y] = x
        edge -= 1

    if edge != 1:
      return False
    return True

