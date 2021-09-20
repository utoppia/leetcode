# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        
        root = TreeNode(preorder[0])
        # st stores the decreasing TreeNode of visited preorder
        st = [root]

        for i in range(1, len(preorder)):
            # Create a new TreeNode
            cur = TreeNode(preorder[i])
            pre = None
            while st and st[-1].val < preorder[i]:
                # if the value of top of st is less than current value
                pre = st[-1]
                st.pop()

            if pre:
                pre.right = cur
            elif st:
                st[-1].left = cur
            # push current value to stack
            st.append(cur)

        return root
        
