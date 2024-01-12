class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # preffix-sum and hash table
        s = [0]
        p = 0
        for a in nums:
            if a == 0:
                p += -1
            else:
                p += a
            s.append(p)

        pos = {}
        ans = 0
        for i in range(len(s)):
            if s[i] not in pos:
                pos[s[i]] = i
            else:
                if ans < i - pos[s[i]]:
                    ans = i - pos[s[i]]
        return ans
