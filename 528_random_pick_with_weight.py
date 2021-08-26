import random
class Solution:

    def __init__(self, w: List[int]):
        self.s = 0
        self.pre_sum = []
        for a in w:
            self.s += a
            self.pre_sum.append(self.s)

    def pickIndex(self) -> int:
        k = random.randint(0, self.s-1)
        return self.binarry_search(k)

    def binarry_search(self, k: int) -> int:
        i, j = 0, len(self.pre_sum)-1
        ans = len(self.pre_sum) - 1
        while i <= j:
            mid = (i + j) // 2
            if self.pre_sum[mid] > k:
                ans = min(ans, mid)
                j = mid - 1
            else:
                i = mid + 1
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
