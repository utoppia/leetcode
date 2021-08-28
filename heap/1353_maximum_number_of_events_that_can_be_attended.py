class Solution:
  def maxEvents(self, events: List[List[int]]) -> int:
    # simulation
    # heap
    events.sort()
    current_date = 1
    heap = []
    pos = 0
    n = len(events)
    ans = 0

    # while there still event doesn't be implemented
    while heap or pos < n:
      if not heap and current_date < events[pos][0]:
        # optimize
        current_date = events[pos][0]

      while pos < n and events[pos][0] <= current_date:
        # from now on, events[pos] can be attended,
        # so we add it to the heap
        heapq.heappush(heap, events[pos][1])
        pos += 1

      while heap and heap[0] < current_date:
        # this event was out of date, drop it
        heapq.heappop(heap)

      if heap:
        # there exists a event can be attended
        ans += 1
        heapq.heappop(heap)

      current_date += 1

    return ans
