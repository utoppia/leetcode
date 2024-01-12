# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        ans = root.val
        que = [root]

        while que:
            n = len(que)
            for i in range(n):
                u = que.pop(0)
                if i == 0:
                    ans = u.val
                if u.left:
                    que.append(u.left)
                if u.right:
                    que.append(u.right)
        return ans
