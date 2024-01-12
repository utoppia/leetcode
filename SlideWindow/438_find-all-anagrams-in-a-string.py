from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        P = {}
        for a in p:
            if a in P:
                P[a] += 1
            else:
                P[a] = 1

        S = {}
        if len(s) < len(p):
            return []

        for i in range(len(p)):
            if s[i] in S:
                S[s[i]] += 1
            else:
                S[s[i]] = 1

        j = len(p)
        i = 0
        ans = []
        if S == P:
            ans = [0]
        while j < len(s):
            if s[j] in S:
                S[s[j]] += 1
            else:
                S[s[j]] = 1

            S[s[i]] -= 1
            if S[s[i]] == 0:
                del S[s[i]]

            i += 1
            j += 1
            if S == P:
                ans.append(i)
        return ans
