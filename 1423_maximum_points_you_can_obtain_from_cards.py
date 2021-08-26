class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        presum = [0]
        cur = 0
        for point in cardPoints:
            cur += point
            presum.append(cur)

        n = len(presum)
        ans = presum[k]
        for i in range(k+1):
            ans = max(ans, presum[n-1] - presum[n-k-1+i] + presum[i])
        return ans
