class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        presum = [0]
        tmp = 0
        for a in s:
            tmp ^= 1 << (ord(a) - ord('a'))
            presum.append(tmp)

        ans = []
        for l, r, k in queries:
            p = presum[r+1] ^ presum[l]
            cnt = 0
            while p:
                if p % 2 != 0:
                    cnt += 1
                p //= 2
            cnt //= 2
            if k >= cnt:
                ans.append(True)
            else:
                ans.append(False)
        return ans
