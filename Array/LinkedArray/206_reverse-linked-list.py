# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def reverseList(self, head: ListNode) -> ListNode:
    if not head or not head.next:
      return head

    u = head
    st = []
    while u:
      st.append(u)
      u = u.next

    st.reverse()
    st.append(None)

    for i in range(len(st) - 1):
      st[i].next = st[i+1]

    return st[0]
      
