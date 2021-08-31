class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
      # heap
      heap = []
      for i in range(len(nums)):
        for j in range(len(nums[i])):
          heapq.heappush(heap, (i+j, j, nums[i][j]))

      ans = []
      while heap:
        ans.append(heapq.heappop(heap)[2])
      return ans
