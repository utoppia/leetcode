class Solution:
  def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
    # inorder traversal
    def update(q: List[TreeNode], root: TreeNode) -> None:
      while root:
        q.append(root)
        root = root.left
    ans = []
    q1, q2 = [], []
    update(q1, root1)
    update(q2, root2)
    while q1 and q2:
      if q1[-1].val <= q2[-1].val:
        root = q1.pop()
        ans.append(root.val)
        root = root.right
        update(q1, root)
      else:
        root = q2.pop()
        ans.append(root.val)
        root = root.right
        update(q2, root)

    if q2:
      q1 = q2

    while q1:
      root = q1.pop()
      ans.append(root.val)
      root = root.right
      update(q1, root)
    return ans
       
