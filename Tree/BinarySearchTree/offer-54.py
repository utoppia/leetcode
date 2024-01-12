# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
  def kthLargest(self, root: TreeNode, k: int) -> int:
    st = []
    ans = []
    while root or st:
      while root:
        st.append(root)
        root = root.left

      root = st.pop()
      ans.append(root.val)
      root = root.right
    return ans[-k]
