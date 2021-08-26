class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)

        left_pos = 0
        while left_pos + 1 < n and nums[left_pos+1] >= nums[left_pos]:
            left_pos += 1

        cur = min(nums[left_pos+1:], default=10**6)

        while left_pos >= 0 and cur < nums[left_pos]:
            left_pos -= 1

        right_pos = n-1
        while right_pos - 1 >= 0 and nums[right_pos-1] <= nums[right_pos]:
            right_pos -= 1

        cur = max(nums[:right_pos], default=-10**6)

        while right_pos < n and cur > nums[right_pos]:
            right_pos += 1

        return max(0, right_pos-left_pos-1)

