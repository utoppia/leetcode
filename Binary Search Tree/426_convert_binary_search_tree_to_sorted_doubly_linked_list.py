class Solution:
  def treeToDoublyList(self, root: 'Node') -> 'Node':
    # inorder traversal

    def inorder(root: Node) -> List[Node]:
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

    arr = inorder(root)
    n = len(arr)
    for i in range(n):
      arr[i].right = arr[(i+1) % n]
      arr[i].left = arr[(i+n-1) % n]
    return arr[0] if arr else None
