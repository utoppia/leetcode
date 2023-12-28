# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-12-29 00:25:12
# filename    : 2496-maximum-value-of-a-string-in-an-array.py
# language    : py
# editor      : Emacs 27.1
# -----------------------------------------


class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max(map(lambda x: int(x) if x.isnumeric() else len(x), strs))
