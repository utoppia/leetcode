# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  base = None
  ans = None
  def update(self, val: int) -> None:
    if self.base == None:
      self.base = val
      return
    if self.ans == None or val - self.base < self.ans:
      self.ans = val - self.base
    self.base = val

  def _f(self, root: TreeNode) -> None:
    if root == None:
      return
    self._f(root.left)
    self.update(root.val)
    self._f(root.right)

  def minDiffInBST(self, root: TreeNode) -> int:
    self._f(root)
    return self.ans
