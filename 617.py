# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if root1 == None and root2 == None:
            return None
        if root1 == None:
            return root2
        if root2 == None:
            return root1
        l = self.mergeTrees(root1.left, root2.left)
        r = self.mergeTrees(root1.right, root2.right)
        return TreeNode(root1.val+root2.val, l, r)
