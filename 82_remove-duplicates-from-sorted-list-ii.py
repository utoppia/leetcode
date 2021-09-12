# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def deleteDuplicates(self, head: ListNode) -> ListNode:
    if not head:
      return head

    pre = None
    p = head
    head = None
    while p:
      q = p
      cnt = 0
      while q and p.val == q.val:
        q = q.next
        cnt += 1

      if cnt == 1:
        if not head:
          head = p
        if pre:
          pre.next = p
        pre = p
        pre.next = None
        p = q
      else:
        p = q

    return head
