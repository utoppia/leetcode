class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        # preffix-sum and hash table
        s = []
        tmp = 0
        for a in nums:
            tmp += a
            s.append(tmp)

        dic = {}
        dic[0] = 1
        ans = 0
        for a in s:
            if a - goal in dic:
                ans += dic[a - goal]

            if a not in dic:
                dic[a] = 1
            else:
                dic[a] += 1
        return ans
