# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return False
        p = root.val
        que = [root]
        while que:
            u = que.pop(0)
            if u.val != p:
                return False
            if u.left:
                que.append(u.left)
            if u.right:
                que.append(u.right)
        return True
