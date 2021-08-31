class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
      # preffix-sum
      # heap

      m, n = len(matrix), len(matrix[0])
      value = [[0] * n for _ in range(m)]

      value[0][0] = matrix[0][0]
      for i in range(1, n):
        value[0][i] = value[0][i-1] ^ matrix[0][i]

      for i in range(1, m):
        value[i][0] = value[i-1][0] ^ matrix[i][0]

      for i in range(1, m):
        for j in range(1, n):
          value[i][j] = value[i-1][j] ^ value[i][j-1] ^ value[i-1][j-1] ^ matrix[i][j]

      heap = []
      index = 0

      for i in range(m):
        for j in range(n):
          if index < k:
            heapq.heappush(heap, value[i][j])
            index += 1
          elif value[i][j] > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, value[i][j])

      return heap[0]

