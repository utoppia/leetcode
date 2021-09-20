# Definition for a binary tree node.
# class TreeNode:
#   def __init__(self, val=0, left=None, right=None):
#     self.val = val
#     self.left = left
#     self.right = right
class Solution:
  def kthSmallest(self, root: TreeNode, k: int) -> int:
    # inorder traversal
    heap = []
    while root or heap:
      while root:
        heap.append(root)
        root = root.left

      root = heap.pop()
      k -= 1
      if k == 0:
        return root.val
      root = root.right

