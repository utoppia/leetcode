# Definition for a binary tree node.
# class TreeNode:
#   def __init__(self, val=0, left=None, right=None):
#     self.val = val
#     self.left = left
#     self.right = right
class Solution:
  def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
    if not root:
      return TreeNode(val)
    p = root
    while p:
      if val > p.val:
        if p.right:
          p = p.right
        else:
          p.right = TreeNode(val)
          break
      else:
        if p.left:
          p = p.left
        else:
          p.left = TreeNode(val)
          break
    return root
