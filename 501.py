# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    base = 0
    count = 0
    ans = []
    maxCount = 0
    def update(self, root: TreeNode) -> None:
        if root.val == self.base:
            self.count += 1
        else:
            self.base = root.val
            self.count = 1
        if self.count == self.maxCount:
            self.ans = self.ans + [root.val]
        if self.count > self.maxCount:
            self.maxCount = self.count
            self.ans = [root.val]

    def _dfs(self, root: TreeNode) -> None:
        if root == None:
            return
        self._dfs(root.left)
        self.update(root)
        self._dfs(root.right)

    def findMode(self, root: TreeNode) -> List[int]:
        self._dfs(root)
        return self.ans

