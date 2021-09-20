class Solution:
  def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
    # simillar with 767 https://leetcode-cn.com/problems/reorganize-string/
    # heap
    heap = []
    for code, cnt in collections.Counter(barcodes).items():
      heapq.heappush(heap, (-cnt, code))

    ans = []
    while heap:
      if len(heap) == 1:
        if heap[0][0] != -1:
          return ""
        else:
          ans.append(heapq.heappop(heap)[1])
        continue

      s1, c1 = heapq.heappop(heap)
      s2, c2 = heapq.heappop(heap)
      ans.append(c1)
      ans.append(c2)
      s1 += 1
      s2 += 1
      if s1:
        heapq.heappush(heap, (s1, c1))
      if s2:
        heapq.heappush(heap, (s2, c2))
    return ans
