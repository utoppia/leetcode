# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def findTarget(self, root: TreeNode, k: int) -> bool:
    if not root:
      return False
    p = root
    queue = [root]
    while queue:
      u = queue.pop()
      if k != 2 * u.val and self.existValue(p, k - u.val):
        return True
      if u.left:
        queue.append(u.left)
      if u.right:
        queue.append(u.right)
    return False

  def existValue(self, root: TreeNode, k: int) -> bool:    
    if not root:
      return False
    if root.val == k:
      return True
    if root.val < k:
      return self.existValue(root.right, k)
    else:
      return self.existValue(root.left, k)
