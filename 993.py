# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root:
            return False
        que = [(root, None)]
        dep = 1
        ans = []
        while que:
            n = len(que)
            for i in range(n):
                u, fa = que.pop(0)
                if u.val == x or u.val == y:
                    ans.append((dep, fa))    
                if u.left:
                    que.append((u.left, u))
                if u.right:
                    que.append((u.right, u))
            dep += 1
        if len(ans) == 2 and ans[0][0] == ans[1][0] and ans[0][1] != ans[1][1]:
            return True
        return False
