class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        presum, cur = [], 0
        for a in nums:
            cur += a
            presum.append(cur)

        ans = 0
        i = len(nums) - 1
        while i > 0:
            l = self.find_left(presum, i-1, cur-presum[i-1])
            r = self.find_right(presum, i-1, cur-presum[i-1])
            ans += (r+1-l)
        return ans % MOD

    def find_left(self, presum: List[int], index: int, val: int) -> int:
        l, r = 0, index-1
        ans = 10 ** 10
        while l <= r:
            mid = (l + r) // 2
            if presum[mid] <= presum[index-1] - presum[mid] and presum[index-1] - presum[mid] <= val:
                ans = min(ans, mid)
                r = mid - 1
            else:
                l = mid + 1

        if ans == 10 ** 10:
            ans = None
        return ans

    def find_right(self, presum: List[int], index: int, val: int) -> int:
        l, r = 0, index-1
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if presum[mid] <= presum[index-1] - presum[mid] and presum[index-1] - presum[mid] <= val:
                ans = max(ans, mid)
                l = mid + 1
            else:
                r = mid - 1

        if ans == -1:
            ans = None
        return ans


