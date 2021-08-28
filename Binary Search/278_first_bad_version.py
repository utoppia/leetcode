# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        ans = n
        while l <= r:
            m = (l+r) // 2
            if isBadVersion(m):
                ans = min(ans, m)
                r = m - 1
            else:
                l = m + 1
        return ans
