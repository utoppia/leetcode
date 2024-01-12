class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10**9+7
        odd_cnt, even_cnt = 0, 1
        cur = 0
        ans = 0
        for a in arr:
            cur = (cur + a) % 2
            if cur == 1:
                ans = (ans + even_cnt) % MOD
                odd_cnt += 1
            else:
                ans = (ans + odd_cnt) % MOD
                even_cnt += 1
        return ans
