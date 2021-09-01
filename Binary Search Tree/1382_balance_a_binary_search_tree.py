class Solution:
  def balanceBST(self, root: TreeNode) -> TreeNode:
    def createBST(arr: List[TreeNode]) -> TreeNode:
      if not arr:
        return None
      n = len(arr) // 2
      root = arr[n]
      root.left = createBST(arr[:n])
      root.right = createBST(arr[n+1:])
      return root

    def inorder(root: TreeNode) -> List[TreeNode]:
      ans = []
      queue = []
      while root or queue:
        while root:
          queue.append(root)
          root = root.left

        root = queue.pop()
        ans.append(root)

        root = root.right
      return ans
    
    return createBST(inorder(root))
