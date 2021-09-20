from heapq import heappush, heappop
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # heap
        # hash table

        arr = {}
        for num in nums:
            if num in arr:
                arr[num] += 1
            else:
                arr[num] = 1

        queue = []
        index = 0

        for num, fre in arr.items():
            if index < k:
                heappush(queue, (fre, num))
                index += 1
            elif queue[0][0] < fre:
                heappop(queue)
                heappush(queue, (fre, num))

        return [j for _, j in queue]
