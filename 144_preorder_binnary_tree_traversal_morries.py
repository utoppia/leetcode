# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        # morris method
        if not root:
            return []

        ans = []
        while root:
            p = root.left

            if p:
                while p.right and p.right != root:
                    p = p.right
                if not p.right:
                    ans.append(root.val)
                    p.right = root
                    root = root.left
                else:
                    p.right = None
                    root = root.right
            else:
                ans.append(root.val)
                root = root.right
        return ans
