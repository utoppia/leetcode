# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # morris method
        ans = []
        pre = None
        while root:
            if root.left:
                pre = root.left
                while pre.right and pre.right != root:
                    pre = pre.right

                if not pre.right:
                    pre.right = root
                    root = root.left

                else:
                    ans.append(root.val)
                    pre.right = None
                    root = root.right

            else:
                ans.append(root.val)
                root = root.right
        return ans
