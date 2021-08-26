# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root:
            return -1
        ans = 2**31
        que = [root]
        p = root.val
        while que:
            u = que.pop(0)
            if u.val > p and u.val < ans:
                ans = u.val
            if u.left:
                que.append(u.left)
            if u.right:
                que.append(u.right)
        return -1 if ans == 2**31 else ans

