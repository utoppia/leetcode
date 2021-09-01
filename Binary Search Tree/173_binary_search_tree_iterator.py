# Definition for a binary tree node.
# class TreeNode:
#   def __init__(self, val=0, left=None, right=None):
#     self.val = val
#     self.left = left
#     self.right = right
class BSTIterator:

  def __init__(self, root: TreeNode):
    self.st = []
    self.root = root
    while root:
      self.st.append(root)
      root = root.left

  def next(self) -> int:
    root = self.st.pop()
    ans = root.val

    root = root.right
    while root:
      self.st.append(root)
      root = root.left
    return ans

  def hasNext(self) -> bool:
    if self.st:
      return True
    return False


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
