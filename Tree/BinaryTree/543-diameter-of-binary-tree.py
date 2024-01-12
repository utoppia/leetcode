# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = 0
    def _f(self, root: TreeNode) -> int:
        if root == None:
            return 0
        l = self._f(root.left)
        r = self._f(root.right)
        if l + r + 1 > self.ans:
            self.ans = l + r
        return max(l, r) + 1

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self._f(root)
        return self.ans

