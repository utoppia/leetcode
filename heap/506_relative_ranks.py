class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        def rankStr(i: int) -> str:
            if i == 0:
                return 'Gold Medal'
            if i == 1:
                return 'Silver Medal'
            if i == 2:
                return 'Bronze Medal'
            return '{}'.format(i+1)
        
        k = {}
        for i in range(len(score)):
            k[i] = score[i]
        rank = sorted(k.items(), key=lambda x: x[1], reverse=True)
        ans = ["" for _ in range(len(score))]
        for i, (pos, _) in enumerate(rank):
            ans[pos] = rankStr(i)
        return ans
