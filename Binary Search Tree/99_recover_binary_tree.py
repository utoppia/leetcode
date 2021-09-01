# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        ans = []
        pre = None
        pre_node = None
        while root:
            if root.left:
                pre = root.left
                while pre.right and pre.right != root:
                    pre = pre.right

                if not pre.right:
                    pre.right = root
                    root = root.left
                else:
                    if not ans and pre_node and root.val < pre_node.val:
                        ans = [pre_node, root]

                    if ans and ans[1].val > root.val:
                        ans[1] = root

                    pre_node = root
                    pre.right = None
                    root = root.right

            else:
                if not ans and pre_node and root.val < pre_node.val:
                    ans = [pre_node, root]

                if ans and ans[1].val > root.val:
                    ans[1] = root

                pre_node = root
                root = root.right
        ans[0].val, ans[1].val = ans[1].val, ans[0].val

