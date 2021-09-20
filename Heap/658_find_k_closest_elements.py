from heapq import heappush, heappop
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # heap 
        # O(nlogn)
        queue = []
        for val in arr:
            heappush(queue, (abs(val-x), val))

        ans = []
        for _ in range(k):
            ans.append(heappop(queue)[1])

        ans.sort()
        return ans
