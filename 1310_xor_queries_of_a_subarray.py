class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        presum = [0]
        cur = 0
        for a in arr:
            cur ^= a
            presum.append(cur)

        ans = []
        for l, r in queries:
            ans.append(presum[l] ^ presum[r+1])
        return ans
