class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        presum = [0]
        cur = 0
        for a in arr:
            cur ^= a
            presum.append(cur)

        ans = 0

        for i in range(len(presum)):
            for j in range(i+1, len(presum)):
                if presum[i] == presum[j]:
                    ans += max(0, j-i-1)

        return ans
