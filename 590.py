"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if root == None:
            return []
        ret = []
        for child in root.children:
            ret = ret + self.postorder(child)
        return ret + [root.val]
