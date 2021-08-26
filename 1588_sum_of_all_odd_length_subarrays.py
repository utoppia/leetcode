class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        s = []
        tmp = 0
        for a in arr:
            tmp += a
            s.append(tmp)

        ans = 0
        s_odd, s_even = 0, 0
        for i in range(len(arr)):
            ans += (i//2+1) * s[i]
            if i % 2 == 0:
                ans -= s_odd
                s_even += s[i]
            else:
                ans -= s_even
                s_odd += s[i]

        return ans

