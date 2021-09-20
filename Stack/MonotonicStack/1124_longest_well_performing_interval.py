class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        def find(dic: List[Tuple[int]], val: int) -> int:
            i, j = 0, len(dic)-1
            ans = j
            while i <= j:
                mid = (i + j) // 2
                if val - dic[mid][0] > 0:
                    ans = min(ans, mid)
                    j = mid - 1
                else:
                    i = mid + 1
            if val - dic[ans][0] > 0:
                return dic[ans][1]
            else:
                return None

        s = []
        tmp = 0
        for a in hours:
            if a > 8:
                tmp += 1
            else:
                tmp -= 1
            s.append(tmp)

        dic = [(0,-1)]
        ans = 0
        for i in range(len(s)):
            k = find(dic, s[i])
            if k != None:
                ans = max(ans, i-k)
            if s[i] < dic[-1][0]:
                dic.append((s[i], i))

        return ans
