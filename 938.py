# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        if not root:
            return 0
        que = [root]
        ans = 0
        while que:
            u = que.pop(0)
            if u.val >= low and u.val <= high:
                ans += u.val
            if u.left:
                que.append(u.left)
            if u.right:
                que.append(u.right)
        return ans
