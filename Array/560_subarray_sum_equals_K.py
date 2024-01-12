class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # preffix-sum and hash table
        s = []
        p = 0
        for a in nums:
            p += a
            s.append(p)

        ans = 0
        pos = {}
        pos[0] = 1
        for a in s:
            if a - k in pos:
                ans += pos[a-k]
            
            if a not in pos:
                pos[a] = 1
            else:
                pos[a] += 1
        return ans
