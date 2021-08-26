class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        ans = []
        cur = 0
        for a in nums:
            cur ^= a
            ans.append((2**maximumBit-1) ^ cur)
        ans.reverse()
        return ans
