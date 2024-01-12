"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        ret = root
        que = [root]
        while que:
            n = len(que)
            pre = None
            for i in range(n):
                u = que.pop(0)
                if pre:
                    pre.next = u
                pre = u
                if u.left:
                    que.append(u.left)
                if u.right:
                    que.append(u.right)
        return root

