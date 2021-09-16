# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
    def valid(u: TreeNode, v: TreeNode) -> bool:
      if not u and not v:
        return True
      if not u or not v:
        return False
      if u.val != v.val:
        return False

      return valid(u.left, v.left) and valid(u.right, v.right)

    q = [root]
    while q:
      u = q.pop(0)
      if valid(u, subRoot):
        return True

      if u.left:
        q.append(u.left)

      if u.right:
        q.append(u.right)

    return False

