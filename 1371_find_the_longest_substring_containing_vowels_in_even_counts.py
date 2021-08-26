class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        # preffix-sum and hash table
        # with ORX operation
        def f(s: str) -> int:
            if s == 'a':
                return 1 << 0
            if s == 'e':
                return 1 << 1
            if s == 'i':
                return 1 << 2
            if s == 'o':
                return 1 << 3
            if s == 'u':
                return 1 << 4
            return 0
        presum = []
        cur = 0
        for ch in s:
            cur ^= f(ch)
            presum.append(cur)

        dic = {}
        dic[0] = -1
        ans = 0
        for i in range(len(presum)):
            if presum[i] in dic:
                ans = max(ans, i-dic[presum[i]])
            else:
                dic[presum[i]] = i
        return ans


