class Solution:
  def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
    queue = []
    ans = []
    while root or queue:
      while root:
        queue.append(root)
        root = root.left

      root = queue.pop()
      ans.append(root)
      root = root.right
    n = len(ans)

    i = 0
    while i < n:
      if ans[i] == p:
        break
      i += 1
    return ans[i+1] if i+1 < n else None
