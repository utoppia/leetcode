# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        ans = []
        que = [root]
        while que:
            n = len(que)
            s = 0
            for i in range(n):
                tmp = que.pop(0)
                s += tmp.val
                if tmp.left:
                    que.append(tmp.left)
                if tmp.right:
                    que.append(tmp.right)
            ans.append(s/n)
        return ans
