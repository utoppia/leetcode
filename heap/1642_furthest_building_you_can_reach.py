class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
      pre = heights[0]
      h = 0
      heap = []
      index = 0
      ans = 0

      for i in range(1, len(heights)):
        if heights[i] <= pre:
          pre = heights[i]
          ans += 1
          continue

        if index < ladders:
          heapq.heappush(heap, heights[i]-pre)
          index += 1
          ans += 1
          pre = heights[i]
          continue

        if heap and heap[0] < heights[i] - pre:
          h += heapq.heappop(heap)
          heapq.heappush(heap, heights[i] - pre)
        else:
          h += heights[i] - pre

        if h > bricks:
          break

        ans += 1
        pre = heights[i]

      return ans

