from heapq import heappush, heappop
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
      my_times = []
      for i, [arrive, leave] in enumerate(times):
        my_times.append((arrive, 1, i))
        my_times.append((leave, -1, i))

      my_times.sort()

      chair = [-1] * len(times)

      queue = []
      # init
      for i in range(len(times)):
        heappush(queue, i)

      for time, status, index in my_times:
        if status == 1: # arrival
          chair[index] = heappop(queue)
        else:
          heappush(queue, chair[index])

      return chair[targetFriend]
