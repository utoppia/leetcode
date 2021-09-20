# Definition for a binary tree node.
# class TreeNode:
#   def __init__(self, val=0, left=None, right=None):
#     self.val = val
#     self.left = left
#     self.right = right
class Solution:
  def convertBST(self, root: TreeNode) -> TreeNode:
    queue = []
    arr = []
    head = root

    while root or queue:
      while root:
        queue.append(root)
        root = root.left

      root = queue.pop()
      arr.append(root)
      root = root.right

    cur = 0
    for node in arr[::-1]:
      cur += node.val
      node.val = cur

    return head
