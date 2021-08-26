class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        s = [0]
        p = 0
        for a in nums:
            p = (p+a) % k
            s.append(p)

        pos = {}
        for i in range(len(s)):
            if s[i] not in pos:
                pos[s[i]] = i
            else:
                if i - pos[s[i]] >= 2:
                    return True
        return False
