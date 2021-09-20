from fractions import Fraction
class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
      # fraction moduler
      # heap

      heap = []
      index = 0
      for i in range(len(arr)):
        for denominator in arr[i+1:]:
          if index < k:
            heapq.heappush(heap, Fraction(-arr[i], denominator))
            index += 1
          elif ( d := Fraction(arr[i], denominator)) < -heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, -d)
      return [-heap[0].numerator, heap[0].denominator]
