class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        tmp = 0
        ans = 0
        for i in gain:
            tmp += i
            if ans < tmp:
                ans = tmp
        return ans
