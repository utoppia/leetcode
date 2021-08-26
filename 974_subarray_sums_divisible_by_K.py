class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        # preffix-sum and hash table
        s = []
        tmp = 0
        for a in nums:
            tmp = (tmp + a) % k
            s.append(tmp)

        dic = {}
        dic[0] = 1
        ans = 0
        for a in s:
            if a in dic:
                ans += dic[a]
                dic[a] += 1
            else:
                dic[a] = 1
        return ans
