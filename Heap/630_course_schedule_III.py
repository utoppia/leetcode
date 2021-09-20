class Solution:
  def scheduleCourse(self, courses: List[List[int]]) -> int:
    # heap

    courses.sort(key = lambda item: (item[1], item[0]))
    heap = []
    total = 0
    for t, d in courses:
      if total + t <= d:
        heapq.heappush(heap, -t)
        total += t
      elif heap and -heap[0] > t:
        total += heapq.heappop(heap)
        heapq.heappush(heap, -t)
        total += t
    return len(heap)

