class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        s = [0] * 55
        for l, r in ranges:
            s[l] += 1
            s[r+1] -=1
        for i in range(1, 51):
            s[i] = s[i] + s[i-1]
        for i in range(left, right+1):
            if s[i] <= 0:
                return False
        return True

