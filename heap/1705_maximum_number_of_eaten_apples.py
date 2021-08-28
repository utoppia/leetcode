from heapq import heappush, heappop
class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
      # every day, we choose the apple with least period date
      # heap

      heap = []
      today, n = 0, len(days)
      ans = 0
      while heap or today < n:
        if today < n:
          if apples[today]:
            heappush(heap, (today+days[today], apples[today]))
        while heap and heap[0][0] <= today:
          heappop(heap)

        if heap:
          d, apple = heappop(heap)
          ans += 1
          apple -= 1
          if apple:
            heappush(heap, (d, apple))
        today += 1

      return ans
