class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        # slide window
        cost = [0]
        tmp = 0
        for i in range(len(s)):
            tmp += abs(ord(s[i]) - ord(t[i]))
            cost.append(tmp)

        ans = 0
        i, j = 0, 1
        n = len(cost)
        while i < n: 
            while j < n and cost[j] - cost[i] <= maxCost:
                j += 1
            ans = max(ans, j-i-1)
            i += 1
        return ans
