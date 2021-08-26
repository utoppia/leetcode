# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = []
        que = [root]

        while que:
            n = len(que)
            for i in range(n):
                u = que.pop(0)
                if i == 0:
                    tmp = u.val
                else:
                    tmp = max(tmp, u.val)

                if u.left:
                    que.append(u.left)
                if u.right:
                    que.append(u.right)
            ans.append(tmp)
        return ans
