# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def maxDepth(self, root: TreeNode) -> int:
    if not root:
      return 0
    ret = 1
    st = [(root, 1)]
    while st:
      u, dep = st.pop()
      ret = max(dep, ret)
      if u.left:
        st.append((u.left, dep + 1))
      if u.right:
        st.append((u.right, dep + 1))

    return ret
