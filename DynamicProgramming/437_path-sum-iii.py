# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

  def pathSum(self, root: TreeNode, targetSum: int) -> int:
    
    def dfs(root: TreeNode, cur: int) -> None:
      nonlocal targetSum, pre
      if not root:
        return 0

      ret = 0
      cur += root.val
      ret += pre[cur - targetSum]
      pre[cur] += 1
      ret += dfs(root.left, cur)
      ret += dfs(root.right, cur)
      pre[cur] -= 1

      return ret

    pre = defaultdict(int)
    pre[0] = 1

    return dfs(root, 0)
  
