# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-12-29 00:56:20
# filename    : 2566-maximum-difference-by-remapping-a-digit.py
# language    : Python
# editor      : Emacs 27.1
# -----------------------------------------


class Solution:
    def minMaxDifference(self, num: int) -> int:

        s = str(num)
        t = s
        for x in s:
            if x != "9":
                t = t.replace(x, "9")
                break

        return int(t) - int(s.replace(s[0], "0"))
