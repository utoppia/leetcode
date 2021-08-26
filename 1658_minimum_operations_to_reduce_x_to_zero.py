class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        # slide window
        # preffix sum
        presum, cur = [0], 0
        for a in nums:
            cur += a
            presum.append(cur)
    
        cur -= x
        i, j = 0, 1
        n = len(presum)
        ans = 10 ** 10
        while i < n:
            j = max(j, i)
            while j < n and presum[j] - presum[i] < cur:
                j += 1

            if j < n and presum[j] - presum[i] == cur:
                ans = min(ans, n - 1 - j + i)

            i += 1

        return ans if ans != 10 ** 10 else -1
