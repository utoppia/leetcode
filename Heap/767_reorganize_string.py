class Solution:
    def reorganizeString(self, s: str) -> str:
      heap = []
      for char, cnt in collections.Counter(s).items():
        heapq.heappush(heap, (-cnt, char))

      ans = ""
      while heap:
        if len(heap) == 1:
          if heap[0][0] != -1:
            return ""
          else:
            ans += heapq.heappop(heap)[1]
          continue

        s1, c1 = heapq.heappop(heap)
        s2, c2 = heapq.heappop(heap)
        ans += c1
        ans += c2
        s1 += 1
        s2 += 1
        if s1:
          heapq.heappush(heap, (s1, c1))
        if s2:
          heapq.heappush(heap, (s2, c2))
      return ans
        
