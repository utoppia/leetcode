class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        # preffix sum and math
        presum, cur = [0], 0
        
        # calculate the preffix sum array
        for a in nums:
            cur += a
            presum.append(cur)

        n = len(nums)
        ans = []
        for i in range(n):
            ans.append((2*i-n+1) * nums[i] + presum[n] - presum[i+1] - presum[i])
        return ans
