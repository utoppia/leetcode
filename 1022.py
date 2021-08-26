# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = 0
    def dfs(self, root: TreeNode, val: int):
        if not root:
            return
        val = val*2 + root.val
        if not root.left and not root.right:
            self.ans += val
        if root.left:
            self.dfs(root.left, val)
        if root.right:
            self.dfs(root.right, val)

    def sumRootToLeaf(self, root: TreeNode) -> int:
        self.ans = 0
        self.dfs(root, 0)
        return self.ans
