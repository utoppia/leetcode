# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = 0
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0

        self.dfs(root, 0)
        return self.ans
    
    def dfs(self, root: TreeNode, val: int):
        
        val = val * 10 + root.val
        if not root.left and not root.right:
            self.ans += val
            return
        if root.left:
            self.dfs(root.left, val)
        if root.right:
            self.dfs(root.right, val)
