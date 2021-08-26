# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        # monotonic stack

        pos = 0
        st = []
        root = head
        n = 0
        while root:
            n += 1
            root = root.next
        ans = [0] * n

        while head:
            pos += 1
            while st and st[-1][0] < head.val:
                ans[st[-1][1]] = head.val
                st.pop()
            
            st.append((head.val, pos-1))
            head = head.next

        return ans


