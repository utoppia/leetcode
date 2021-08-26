# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = []
    def dfs(self, root: TreeNode, targetSum: int, path: List[int], currentSum: int):
        path = path + [root.val]
        currentSum += root.val
        if not root.left and not root.right:
            if currentSum == targetSum:
                self.ans.append(path)
            return 
        if root.left:
            self.dfs(root.left, targetSum, path, currentSum)
        if root.right:
            self.dfs(root.right, targetSum, path, currentSum)
        
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []
        self.ans = []
        self.dfs(root, targetSum, [], 0)
        return self.ans
