class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        s = [0]
        tmp = 0
        for a in nums:
            tmp += a
            s.append(tmp)

        i, j = 0, 0
        ans = None
        n = len(s)
        while i < n:
            while j < n and s[j] - s[i] < target:
                j += 1
            if j < n and s[j] - s[i] >= target:
                if not ans or ans > j - i:
                    ans = j - i
            i += 1
        if not ans:
            ans = 0
        return ans
