# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
    tmp = []
    p = head
    while p:
      tmp.append(p)
      p = p.next

    n = len(tmp)

    cnt = n // k
    j = n % k

    pos = 0
    ans = []
    for _ in range(k):
      if pos < n:
        ans.append(tmp[pos])

        pos += cnt
        if j > 0:
          pos += 1
          j -= 1

        tmp[pos - 1].next = None
      else:
        ans.append(None)

    return ans
