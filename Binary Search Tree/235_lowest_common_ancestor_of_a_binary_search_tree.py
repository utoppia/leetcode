# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
  ans = None
  def _dfs(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> bool:
    if root == None:
      return False
    l = self._dfs(root.left, p, q)
    r = self._dfs(root.right, p, q)
    if (l and r) or ((root.val == p.val or root.val == q.val) and (l or r)):
      self.ans = root
    return root.val == p.val or root.val == q.val or l or r

  def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    self.ans = None
    self._dfs(root, p, q)
    return self.ans
