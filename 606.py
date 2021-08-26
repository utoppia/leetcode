# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: TreeNode) -> str:
        if root == None:
            return ''
        ret = '{}'.format(root.val)
        l = self.tree2str(root.left)
        r = self.tree2str(root.right)
        if l == '' and r == '':
            return ret
        if l != '' and r == '':
            return ret + '({})'.format(l)
        return ret + '({})({})'.format(l, r)
