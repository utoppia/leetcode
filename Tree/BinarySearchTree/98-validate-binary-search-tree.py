# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def dfs(self, root: TreeNode) -> (bool, int, int):
    if not root.left and not root.right:
      return True, root.val, root.val
    x_min, x_max = root.val, root.val
    if root.left:
      is_left, left_min, left_max = self.dfs(root.left)
      if not is_left or left_max >= root.val:
        return False, -1, -1
      x_min = min(x_min, left_min)
      x_max = max(x_max, left_max)
    if root.right:
      is_right, right_min, right_max = self.dfs(root.right)
      if not is_right or right_min <= root.val:
        return False, -1, -1
      x_min = min(x_min, right_min)
      x_max = max(x_max, right_max)
    return True, x_min, x_max

  def isValidBST(self, root: TreeNode) -> bool:
    if not root:
      return True
    ans,_,_ = self.dfs(root)
    return ans
