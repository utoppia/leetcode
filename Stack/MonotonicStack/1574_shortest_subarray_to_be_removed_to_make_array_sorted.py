class Solution:
    def findLengthOfShortestSubarray(self, nums: List[int]) -> int:
        # simillar with #581

        n = len(nums)

        left_pos = 0
        while left_pos + 1 < n and nums[left_pos+1] >= nums[left_pos]:
            left_pos += 1

        ans = n - left_pos - 1

        right_pos = n - 1
        i = left_pos 
        while right_pos > 0:
            while i >= 0 and (i >= right_pos or nums[i] > nums[right_pos]):
                i -= 1
            ans = min(ans, right_pos - i - 1)
            
            if nums[right_pos-1] <= nums[right_pos]:
                right_pos -= 1
            else:
                break

        return ans
