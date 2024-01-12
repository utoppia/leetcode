class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        front = [1]
        p = 1
        for a in nums:
            p *= a
            front.append(p)
        back = [1]
        p = 1
        for a in nums[::-1]:
            p *= a
            back.append(p)
        ans = []
        n = len(nums)
        for i in range(n):
            ans.append(front[i] * back[n-1-i])
        return ans
