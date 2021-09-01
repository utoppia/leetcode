# Definition for a binary tree node.
# class TreeNode:
#   def __init__(self, val=0, left=None, right=None):
#     self.val = val
#     self.left = left
#     self.right = right
class Solution:
  def increasingBST(self, root: TreeNode) -> TreeNode:
    queue = []
    pre = None
    while root or queue:
      while root:
        queue.append(root)
        root = root.left

      root = queue.pop()
      if pre:
        pre.right = root
      else:
        head = root
      root.left = None
      pre = root
      root = root.right

    return head

