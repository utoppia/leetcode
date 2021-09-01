# Definition for singly-linked list.
# class ListNode:
#   def __init__(self, val=0, next=None):
#     self.val = val
#     self.next = next
# Definition for a binary tree node.
# class TreeNode:
#   def __init__(self, val=0, left=None, right=None):
#     self.val = val
#     self.left = left
#     self.right = right
class Solution:
  def sortedListToBST(self, head: ListNode) -> TreeNode:
    def dfs(arr: List[int]) -> TreeNode:
      if not arr:
        return None
      n = len(arr) // 2
      root = TreeNode(arr[n])
      root.left = dfs(arr[:n])
      root.right = dfs(arr[n+1:])
      return root

    arr = []
    while head:
      arr.append(head.val)
      head = head.next
    return dfs(arr)

