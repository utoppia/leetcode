class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
      # max-heap

      def distance(point: List[int]) -> int:
        return point[0] ** 2 + point[1] ** 2

      heap = []
      index = 0

      for point in points:
        if index < k:
          heapq.heappush(heap, (-distance(point), point))
          index += 1
        elif (d := distance(point)) < -heap[0][0]:
          heapq.heappop(heap)
          heapq.heappush(heap, (-d, point))

      return heap
