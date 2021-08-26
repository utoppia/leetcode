class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        n = len(nums)
        diff = [0] * (n+1)
        for l, r in requests:
            diff[l] += 1
            diff[r+1] -= 1

        cur = 0
        s = []
        for i in range(n):
            cur += diff[i]
            s.append(cur)

        s.sort()
        nums.sort()
        ans = 0
        for i in range(n):
            ans += s[i] * nums[i]
        return ans % (10 ** 9 + 7)

