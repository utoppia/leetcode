# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2024-01-12 21:05:17
# filename    : 46-permutations.py
# language    : Python
# editor      : Emacs 27.1
# -----------------------------------------

import copy
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        visited = [False for _ in range(len(nums))]

        def dfs(nums, path, answers):
            if len(path) == len(nums):
                answers.append(copy.deepcopy(path))
                return
            for i in range(len(nums)):
                if not visited[i]:
                    visited[i] = True
                    path.append(nums[i])
                    dfs(nums, path, answers)
                    visited[i] = False
                    path.pop()
            return

        answers = []
        dfs(nums, [], answers)
        return answers
