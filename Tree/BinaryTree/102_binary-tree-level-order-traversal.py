# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def levelOrder(self, root: TreeNode) -> List[List[int]]:
    ret = []
    if not root:
      return ret

    st = [(root, 0)]
    ret = [[]]

    while st:
      u, dep = st.pop()
      if len(ret) == dep:
        ret.append([])
      ret[dep].append(u.val)

      if u.right:
        st.append((u.right, dep + 1))
      if u.left:
        st.append((u.left, dep + 1))

    return ret
