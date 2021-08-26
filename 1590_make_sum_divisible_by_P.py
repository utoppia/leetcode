class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        presum = []
        cur = 0
        for a in nums:
            cur = (cur + a) % p
            presum.append(cur)

        val = presum[-1]
        if val == 0:
            return 0
        dic = {0:-1}
        ans = 10 ** 10
        for i in range(len(presum)):
            t = (presum[i] - val + p) % p
            if t in dic:
                ans = min(ans, i-dic[t])
            dic[presum[i]] = i
        return -1 if ans == 10 ** 10 or ans == len(presum) else ans
