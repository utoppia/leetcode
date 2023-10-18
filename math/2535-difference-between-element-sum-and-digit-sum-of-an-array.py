# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-10-18 23:53:53
# filename    : difference-between-element-sum-and-digit-sum-of-an-array
# language    : py
# -----------------------------------------


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        return abs(sum(nums) - sum(map(int, "".join(map(str, nums))[:])))
